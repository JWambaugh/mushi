<?
	function(command,ret){
		//_log("getAll command called.");
		//only do somthig if our command was called
		if(command.command=="getAll"){
			include(_config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api
		//	_log("command is getAll");
			ret.tickets = Mushi.getTasks();
		//	_log(debug(ret));
			ret.status='success';
		}
		return ret;
	}

