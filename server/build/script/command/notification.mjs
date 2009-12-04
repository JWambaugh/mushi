<?
//This command sends a notification email each time a new task is created.
	(function(command,ret){
		//only do somthig if our command was called
		if(command.command=="addTask"){
			//send an email!
				var headers="MIME-Version: 1.0\nContent-type: text/html; charset=iso-8859-1\n";
			Mushi.sendMail("jwambaugh@rae.bz","jordan@wambaugh.org","New task: "+command.title,"Title: "+command.title+"\nDescription: "+command.description,headers);
		}
		return ret;
	})

