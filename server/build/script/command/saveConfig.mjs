<?
	//"saveConfig" command. saves a specific config parameter.
	(function(command,ret){
		//only do somthing if our command was called
		if(command.command=="saveConfig"){
			//Mushi.include(Mushi.config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api
            var db = Mushi.db;
			Mushi.db.exec("delete from config where key='"+db.escapeQuotes(command.key)+"'");
            Mushi.db.exec("insert into config (key,value,description) values ('"+db.escapeQuotes(command.key)+"','"+db.escapeQuotes(command.value)+"','"+db.escapeQuotes(command.description)+"')");
			ret.status='success';
            ret.success=1;
		}
		return ret;
	})

