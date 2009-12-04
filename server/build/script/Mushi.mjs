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
	var q="insert into task (title,description) values ('"+title+"','"+description+"')";
	return this.db.exec(q);
};


/*
 Set up a shortcut to Mushi.conn.print()
*/
Mushi.print=Mushi.conn.print;
