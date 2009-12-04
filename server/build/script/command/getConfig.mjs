<?
	//"getConfig" command, returns all config parameters in the system. 
	(function(command,ret){
		//only do somthig if our command was called
		if(command.command=="getConfig"){
			//Mushi.include(Mushi.config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api
			ret.data = Mushi.db.select("select * from config order by key");
            
			ret.status='success';
		}
		return ret;
	})

