<?
(function(command,ret){
    with(Mushi){
		//only do somthing if our command was called
		if(command.command=="addRightToRole"){
        
            //make sure all required params are given
            if(Mushi.und(command.roleID)==''||Mushi.und(command.rightID)=''){
                ret.status='error';
                ret.message='roleID and rightID required.';
                return ret;
            }
            
            
            
        
			Mushi.db.exec(Mushi.db.object2Insert(command,['roleID','rightID'],"roleRight"));
			ret.status='success';
		}
		return ret; //always return the ret value.
    }
})