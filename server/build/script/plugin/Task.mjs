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
                                + " ,t.ownerId as ownerID, t.parentTaskID, o.firstName as owner_firstName, o.lastName as owner_lastName"
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