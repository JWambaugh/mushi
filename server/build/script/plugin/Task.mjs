<?


/**
 * Mushi sample plugin
 * keep in mind a new plugin object is instantiated for every request.
 */
Mushi.Plugin.add({
    
    
    //Name of the plugin
    _name:'Task Plugin'
    
    
    /**
     * Always executed when pluggin is loaded. Note this is called every time a plugin object is instantiated. This includes on server initialization and on every command and .mjs request.
     */
    ,_construct:function(){
        //Mushi.log(this._name+' has been loaded!');
    }
    
    /**
     * Called when a command is executed
     * MUST return ret object!
     */
    ,_commandHandler:function(command,ret){
        with(Mushi){
            //only do somthig if our command was called
            
            /**
             * addNoteToTask command
             **/
            if(command.command=="addNoteToTask"){
                Mushi.addNoteToTask(command.taskID,command.text,command.timeSpent,command.authorID);
                ret.status='success';
            }
            
            /**
             * getTaskNotes command
             */
            else if(command.command=="getTaskNotes"){
                // Mushi.log(command)
                if(typeof(command.taskID)=='undefined' || command.taskID==''){
                    ret.status='failure';
                    ret.message='Must provide a taskID of task to get notes for.';
                    ret.reason='Missing parameter';
                    return ret;
                }
                ret.data=getTaskNotes(command.taskID);
                ret.status='success';
            }
            
            else if(command.command=='findTask'){
                var query="SELECT t.id, t.title, t.percentComplete, t.estimate, t.createDate"
                                + " , t.reporterID, r.firstName as reporter_firstName, r.lastName as reporter_lastName"
                                + " ,t.ownerId as ownerID, t.parentTaskID,t.dueDate, o.firstName as owner_firstName, o.lastName as owner_lastName"
                                + " ,s.name as status_name, s.isOpen as status_isOpen, s.id as status_id"
                                + " FROM task t"
                                + " LEFT JOIN user r on r.id = t.reporterID"
                                + " LEFT JOIN user o on o.id = t.ownerID"
                                + " LEFT JOIN status s on s.id = t.statusID";
                var operator=coalesce(command.operator,"and");
                
                if(operator=='and'){
                    query =query+' WHERE 1';
                }
                var params=[{name:'title',value:'title'}
                               ,{name:'taskID',value:'t.id'}
                               ,{name:'isOpen',value:'s.isOpen'}
                            ];
                
                for(var x=0;x<params.length;x++){
                    if(und(command[params[x].name])){
                        query=query + " "+operator+" "+params[x].value+"='"+escapeQuotes(command[params[x].name])+"'";
                    }
                }
                //log(query);
                ret.results=db.nestedSelect(query);
            }
            
            /**
             *  editTask command
             *  updates a task with new data passed in command
             */
            else if(command.command == 'editTask'){
                if(und(command.title)==''){
                    ret.status='failure';
                    ret.message='Task title cannot be empty!';
                    return ret;
                }
                if(und(command.id)==""){
                    ret.status='failure';
                    ret.message='Task id must be provided to edit task!';
                    return ret;
                }
                //get current state of task
                var currentState = db.nestedSelect(
                                "SELECT t.id, t.title, t.description, t.percentComplete, t.estimate, t.createDate, t.originalEstimate"
                                + " , t.reporterID, r.firstName as reporter_firstName, r.lastName as reporter_lastName, r.email as reporter_email "
                                + " ,t.ownerId as ownerID, t.parentTaskID,t.dueDate, o.firstName as owner_firstName, o.lastName as owner_lastName, o.email as owner_email "
                                + " ,s.name as status_name, s.isOpen as status_isOpen, s.id as status_id"
                                + " ,ty.id as type_id,ty.name as type_name, ty.description as type_description"
                                + " ,p.id as priority_id, p.name as priority_name, p.description as priority_description"
                                + " FROM task t"
                                + " LEFT JOIN user r on r.id = t.reporterID"
                                + " LEFT JOIN user o on o.id = t.ownerID"
                                + " LEFT JOIN status s on s.id = t.statusID"
                                + " LEFT JOIN type ty on t.typeID = ty.id"
                                + " LEFT JOIN Priority p on p.id = t.priorityID"
                                + " where t.id = "+escapeQuotes(command.id));
                //trigger our pre-update event
                Plugin.triggerEvent("Task_preEditTask",{currentState:currentState[0],updateCommand:command});
                
                var columns = ['title'
                               ,'originalEstimate'
                               ,'description'
                               ,'percentComplete'
                               ,'reporterId'
                               ,'ownerId'
                               ,'projectID'
                               ,'estimate'
                               ,'categoryID'
                               ,'parentTaskID'
                               ,'statusID'
                               ,'dueDate'
                               ];
                var query=db.json2Update(command,columns,'id = '+command.id,'task');
                db.exec(query);
                ret.status='success';
                //trigger our post-update event
                Plugin.triggerEvent("Task_postEditTask",{currentState:currentState[0],updateCommand:command});
               
            }
            
            else if(command.command=="getTask"){
                if(!und(command.taskID)){
                    ret.status='error';
                    ret.message='taskId not provided';
                    return ret;
                }
                var query="SELECT t.id, t.title, t.description, t.percentComplete, t.estimate, t.createDate, t.originalEstimate"
                            + " , t.reporterID, r.firstName as reporter_firstName, r.lastName as reporter_lastName, r.email as reporter_email "
                            + " ,t.ownerId as ownerID, t.parentTaskID,t.dueDate, o.firstName as owner_firstName, o.lastName as owner_lastName, o.email as owner_email "
                            + " ,s.name as status_name, s.isOpen as status_isOpen, s.id as status_id"
                            + " ,ty.id as type_id,ty.name as type_name, ty.description as type_description"
                            + " ,p.id as priority_id, p.name as priority_name, p.description as priority_description"
                            + " FROM task t"
                            + " LEFT JOIN user r on r.id = t.reporterID"
                            + " LEFT JOIN user o on o.id = t.ownerID"
                            + " LEFT JOIN status s on s.id = t.statusID"
                            + " LEFT JOIN type ty on t.typeID = ty.id"
                            + " LEFT JOIN Priority p on p.id = t.priorityID"
                            + " WHERE t.id = '" +escapeQuotes(command.taskID)+"'";
                
                ret.results=db.nestedSelect(query);
                ret.status='success';
                
                
            }
            
            
            
            
            return ret;
        }
        
       
    }
    
    /**
     * called only once, at system startup
     */
    ,_systemInit:function(){
        Mushi.log("Task plugin initialized.");
    }
    


});