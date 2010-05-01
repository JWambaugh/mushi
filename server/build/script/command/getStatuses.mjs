<?
(function(command,ret){
    	

	//"getStatuses" command - returns all registered statuses.
    
		//only do somthig if our command was called
		if(command.command=="getStatuses"){
					ret.statuses = Mushi.getStatuses();
			ret.status='success';
		}
		return ret;
})

