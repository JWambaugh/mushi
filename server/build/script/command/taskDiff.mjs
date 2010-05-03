<?
/**
 * taskDiff command module
 * Author: Jordan Wambaugh
 * Create Date: 2010-05-03
 *
 * Records changes in a task as a note.
 *
 */
(function(command,ret){
    with(Mushi){
		
        //plug into the editTask command
		if(command.command=="editTask"){
			//get original task
            log(debug(command))
            /*
            var task = db.nestedSelect("SELECT t.id, t.title, t.description, t.percentComplete, t.estimate, t.createDate,t.originalEstimate" 
				+ " , t.reporterId as reporterId, r.firstName as reporter_firstName, r.lastName as reporter_lastName, r.email as reporter_email "
				+ " ,t.ownerId as ownerId, o.firstName as owner_firstName, o.lastName as owner_lastName, o.email as owner_email "
				+ " ,s.name as status_name, s.isOpen as status_isOpen, s.id as status_id"
				+ " FROM task t"
				+ " LEFT JOIN user r on r.id = t.reporterId"
				+ " LEFT JOIN user o on o.id = t.ownerId"
				+ " LEFT JOIN status s on s.id = t.statusID"
				+ " WHERE t.id="+db.escapeQuotes(command.id));
            */
            task=command.originalTask.results[0];
            
            var buffer='';
            
            /*
            PATERN:
            [OriginalValue , NewValue, Label]
            */
            var compareRows = [
                               [task.description, command.description, "Description"]
                               ,[task.estimate, command.estimate, "Estimate"]
                               ,[task.originalEstimate, command.originalEstimate, "Original Estimate"]
                               ,[task.title, command.title, "Title"]
                               ,[task.status.name, command.status.name, "Status"]
                               ,[task.reporter.firstName+" "+task.reporter.lastName, command.reporter.firstName+" "+command.reporter.lastName, "Reporter"]
                               ,[task.owner.firstName+" "+task.owner.lastName, command.owner.firstName+" "+command.owner.lastName, "Owner"]
                               ,[task.percentComplete, command.percentComplete, "% Complete"]
                               ]
            
            for(var x=0;x<compareRows.length;x++){
                var row = compareRows[x];
                if(row[0]!=row[1]){
                    buffer = buffer + "<li>" +  row[2] + ": '" + row[0] + "' -> '" + row[1] + "'</li>";
                }
            }
            
            Mushi.log("original task:"+debug(task));
            if(buffer!=''){
                buffer = "The following changes were made: <ul>" + buffer + "</ul>";
                Mushi.addNoteToTask(command.id,buffer,"","");
                var emailServer = Mushi.config.getValue("SMTPServer");
                if(emailServer!=''){
                    sendMail(config.getValue("adminEmail"),"jordan@wambaugh.org","Task Changed: "+task.title,buffer,"MIME-Version: 1.0'\nContent-type: text/html; charset=iso-8859-1");
                }
            }
		}
        
		return ret;
    }
})

