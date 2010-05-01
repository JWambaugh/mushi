<?
(function(command,ret){
    with (Mushi) {

	//"getAllRights" command - returns all registered statuses.
        
		//only do somthig if our command was called
		if(command.command=="getAllRights"){
           // Mushi.log(command)
           
			ret.data=getRights();
			ret.status='success';
		}
		return ret;
    }
})

