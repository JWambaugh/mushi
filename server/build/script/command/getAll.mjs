<?
	//"Get all" command, returns all tasks in the system. Prolly not really useful since findTask does the same thing, but a lot faster.
	(function(command,ret){
		//only do somthig if our command was called
		if(command.command=="getAll"){
			Mushi.include(Mushi.config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api
			ret.tickets = Mushi.getTasks();
			ret.status='success';
		}
		return ret;
	})

