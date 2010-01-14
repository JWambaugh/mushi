<?
Mushi.include(Mushi.config.getValue("scriptDirectory")+'/Mushi.mjs'); //Load the Mushi javascript api
(function(command,ret){
    with (Mushi) {

	//"getStatuses" command - returns all registered statuses.
        
		//only do somthig if our command was called
		if(command.command=="getTaskNotes"){
           // Mushi.log(command)
            if(typeof(command.taskID)=='undefined' || command.taskID==''){
                ret.status='failure';
                ret.message='Must provide a taskID of task to get notes for.';
                ret.reason='Missing parameter';
                return ret;
            }
			ret.data=getTaskNotes(command.taskID);
			ret.status='success';
		}
		return ret;
    }
})

