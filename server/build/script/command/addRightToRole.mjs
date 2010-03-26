<?
(function(command,ret){
    with(Mushi){
		//only do somthing if our command was called
		if(command.command=="addRightToRole"){
        
            //make sure all required params are given
            if(und(command.roleID)==''||und(command.rightID)==''){
                ret.status='error';
                ret.message='roleID and rightID required.';
                return ret;
            }
            
            
            
        
			db.exec(Mushi.db.object2Insert(command,['roleID','rightID'],"roleRight"));
			ret.status='success';
		}
		return ret; //always return the ret value.
    }
})