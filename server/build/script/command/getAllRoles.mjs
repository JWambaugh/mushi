<?
(function(command,ret){
    with (Mushi) {

	//"getAllRoles" command - returns all registered statuses.
        
		//only do somthig if our command was called
		if(command.command=="getAllRoles"){
           // Mushi.log(command)
            
            //validate we have a projectID
            if(validate.required(command,ret, ['projectID'])){
                return ret;
            }
			ret.data=getRoles(command['projectID']);
			ret.status='success';
		}
		return ret;
    }
})

