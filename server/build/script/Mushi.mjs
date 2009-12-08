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
    var tasks=this.db.select("select * from notes where tableName='task' and someID='"+this.db.escapeQuotes(taskID)+"'");
    return tasks;
}

Mushi.db.getInsertRowID=function(){
    var id=this.select("select last_insert_rowid() as rowid");
    return id[0].rowid;
}

Mushi.addNoteToTask=function(taskID,note,timeSpent,authorID){
    this.db.exec("insert into note (someID,tableName,timeSpent,authorID) values ('"+taskID+"','task','"+this.db.escapeQuotes(timeSpent)+"','"+this.db.escapeQuotes(authorID)+"')");
    var id=Mushi.db.getInsertRowID()
    this.db.exec("insert into textHistory (someID,tableName,text) values ('"+id+"','note','"+note+"')");
}


/*
 Set up a shortcut to Mushi.conn.print()
*/
Mushi.print=Mushi.conn.print;
