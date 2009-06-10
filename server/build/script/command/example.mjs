<?
	function(command,ret){
		//only do somthig if our command was called
		if(command.command=="findTask"){
			for(i in ret.results){
				var task=ret.results[i];
				task.title=task.title+"Appended!"
			}
		}
		return ret;
	}

