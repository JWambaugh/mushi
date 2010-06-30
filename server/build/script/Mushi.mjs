<?

/*
supplimental methods to the Mushi global object


*/

Mushi.getTasks = function(){
	var query="SELECT t.id, t.title, t.description, t.percentComplete, t.estimate, t.createDate" 
				+ " , t.reporterId as reporterId, r.firstName as reporter_firstName, r.lastName as reporter_lastName, r.email as reporter_email "
				+ " ,t.ownerId as ownerId, o.firstName as owner_firstName, o.lastName as owner_lastName, o.email as owner_email "
				+ " ,s.name as status, s.isOpen as isOpen"
				+ " FROM task t"
				+ " LEFT JOIN user r on r.id = t.reporterId"
				+ " LEFT JOIN user o on o.id = t.ownerId"
				+ " LEFT JOIN status s on s.id = t.statusID"
				+ " WHERE 1";
	return this.db.nestedSelect(query);
};



Mushi.getStatuses = function(){
	var query="SELECT * from status" 
			+ " WHERE 1";
	return this.db.nestedSelect(query);
}


Mushi.newTask=function(title,description){
	var q="insert into task (title,description) values ('"+this.db.escapeQuotes(title)+"','"+this.db.escapeQuotes(description)+"')";
	return this.db.exec(q);
};

/**
 * Returns an array of task objects that belong to a particular task
 **/
Mushi.getTaskNotes=function(taskID){
    var tasks=this.db.select("select n.id as id, timeSpent, authorID,n.createDate as noteCreateDate,th.id as historyID, text from note n"
                            +" join textHistory th on th.someID=n.id and th.tableName='note' and th.id= (select max(id) from textHistory sth where sth.someID=n.id and sth.tableName='note')"
                            +" where n.tableName='task' and n.someID='"+this.db.escapeQuotes(taskID)+"'");
    return tasks;
}




Mushi.getRoles = function(projectID){
    var query = "select * from role where projectID ='"+Mushi.escapeQuotes(Mushi.und(projectID))+"'";
    Mushi.log(query)
    return this.db.nestedSelect(query);
}

Mushi.getRights = function(roleId){
    var where = '1'
    if(this.und(roleId)!=''){
        where =roleId;
    }
    var query = "select * from right where " + where;
    return this.db.nestedSelect(query);
}






/**
 * Mushi.db additional helper functions
 */

/**
 * Returns the ID of the last insert
 */
Mushi.db.getInsertRowID=function(){
    var id=this.select("select last_insert_rowid() as rowid");
    Mushi.log(id)
    return id[0].rowid;
}


/**
 * Builds an insert statement from an object
 */
Mushi.db.object2Insert=function(obj,columns,table){
   var buffer="INSERT INTO "+table+" ("+columns.join(", ")+") VALUES (";
   for (var x=0;x<columns.length;x++){
        if(x>0)buffer=buffer+", "
        buffer=buffer+"'"+Mushi.escapeQuotes(obj[columns[x]])+"'";
   }
   buffer=buffer+")";
   return buffer;
}

/**
 * Builds an update statement from an object
 */
Mushi.db.object2Update=function(obj,columns,where,table){
   var buffer="UPDATE "+table+" SET ";
   for (var x=0;x<columns.length;x++){
        if(x>0)buffer=buffer+", "
        buffer=buffer+columns[x]+" = '"+Mushi.escapeQuotes(obj[columns[x]])+"'";
   }
   buffer=buffer+" WHERE "+where;
   return buffer;
}








/**
 * Adds a note to a task
 */
Mushi.addNoteToTask=function(taskID,note,timeSpent,authorID){
    this.db.exec("insert into note (someID,tableName,timeSpent,authorID) values ('"+taskID+"','task','"+this.escapeQuotes(timeSpent)+"','"+this.escapeQuotes(authorID)+"')");
    var id=Mushi.db.getInsertRowID()
    this.db.exec("insert into textHistory (someID,tableName,text) values ('"+id+"','note','"+this.escapeQuotes(note)+"')");
}




/**
 *Simple command validation API
 */
Mushi.validate={
    required:function(command,ret,fields){
        for(var field in fields){
            if (Mushi.und(command[fields[field]])==''){
                ret.message='Required field '+fields[field]+' was not specified.';
                ret.status='error';
                return 1;
            }
        }
        return 0;
    }
}





/***
 * Plugins API
 */


Mushi.Plugin={
	registeredPlugins:[]
    
    ,registeredEventHandlers:[]
    
	,add : function(pluginObject){
		if(typeof(pluginObject._construct)=='function'){
			pluginObject._construct();
		}
		this.registeredPlugins.unshift(pluginObject);
	}
	
	,systemInit: function(){
		//Mushi.log("systemInit called. Total plugins loaded: "+this.registeredPlugins.length);
		for(var x=0;x<this.registeredPlugins.length;x++){
			if(typeof(this.registeredPlugins[x]._systemInit)=='function'){
				this.registeredPlugins[x]._systemInit();
			}
		}
	}
    
    /**
     * Adds an event handler to the system.
     * Plugins may define their own event handlers using this function.
     * Each handler should be an object with the following properties:
     *      name - The name of the event to handle
     *      handler - the function to be executed when the event is triggered
     */
    ,addEventHandler:function(handler){
        if(!Mushi.und(handler.name) || !Mushi.und(handler.handler)){
            return null;
        }
        this.registeredEventHandlers.unshift(handler);
    }
    
    /**
     * runs all handlers with handlerName, passing args to the registered handlers lambdas.
     * Plugins may define their own events by simply calling this function with a unique eventName
     * returns an array of returned values from each handler
     */
    ,triggerEvent:function(eventName,args){
        var retVal=[];
        for(var x=0;x<this.registeredEventHandlers.length;x++){
            var handler = this.registeredEventHandlers[x];
            if(handler.name==eventName){
                retVal.unshift(handler.handler(args));
            }
        }
        return retVal;
    }
}







/**
 *UTILITIES
 */


/**
 * Returns an emtpy string if val is undefined. Otherwise returns val.
 */
Mushi.und=function(val){
    if(typeof(val)=='undefined')return "";
    else return val;
}

/**
 * Mushi.db.escapequote shortcut with added wrapping in Mushi.und to clean up undefined values
 */
Mushi.escapeQuotes=function(val){
    return this.db.escapeQuotes(this.und(val));
}

Mushi.coalesce = function(value,ifnull){
    if(!Mushi.und(value))return(ifnull);
    return(ifnull);
}


/**
 * Clones an object
 **/
Mushi.clone = function(obj) {
    // A clone of an object is an empty object 
    // with a prototype reference to the original.

    // a private constructor, used only by this one clone.
            function Clone() { } 
    Clone.prototype = obj;
    var c = new Clone();
            c.constructor = Clone;
            return c;
}

Mushi.runCommand = Mushi.engine.runCommand;


Mushi.logd=function(data){
    this.log(debug(data));
}



Mushi.stripTags=function(str,config){
    if(config.removeHead)
        str=str.replace(/<head>[^]*<\/head>/gim,'');
    str=str.replace(/<\w+(\s+("[^"]*"|'[^']*'|[^>])+)?>|<\/\w+>/gi, '');
    return str;
}


if(Mushi.conn){
	/*
	 Set up a shortcut to Mushi.conn.print()
	*/
	Mushi.print=Mushi.conn.print;
}else{
	Mushi.print=Mushi.log;
}



String.prototype.replaceAll = function(
    strTarget, // The substring you want to replace
    strSubString // The string you want to replace in.
    ){
    var strText = this;
    var intIndexOfMatch = strText.indexOf( strTarget );
     
    // Keep looping while an instance of the target string
    // still exists in the string.
    while (intIndexOfMatch != -1){
    // Relace out the current instance.
    strText = strText.replace( strTarget, strSubString )
     
    // Get the index of any next matching substring.
    intIndexOfMatch = strText.indexOf( strTarget );
    }
     
    // Return the updated string with ALL the target strings
    // replaced out with the new substring.
    return( strText );
}

