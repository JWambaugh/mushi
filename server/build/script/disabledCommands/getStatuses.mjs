<?
	include(_config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api

	//"getStatuses" command - returns all registered statuses.
getGlobalObject().Mushi.runCommand=function(command,ret){
		//only do somthig if our command was called
		if(command.command=="getStatuses"){
					ret.statuses = Mushi.getStatuses();
			ret.status='success';
		}
		return ret;
	}

