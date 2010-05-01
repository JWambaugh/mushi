<?
(function(command,ret){
    with(Mushi){
		//only do somthig if our command was called
		if(command.command=="addNoteToTask"){
			Mushi.addNoteToTask(command.taskID,command.text,command.timeSpent,command.authorID);
			ret.status='success';
		}
		return ret;
    }
})

