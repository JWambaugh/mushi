<?
Mushi.include(Mushi.config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api
(function(command,ret){
    with(Mushi){
		//only do somthig if our command was called
		if(command.command=="addNoteToTask"){
			Mushi.addNoteToTask(command.taskID,command.note,command.command.timeSpent,command.authorID);
			ret.status='success';
		}
		return ret;
    }
})

