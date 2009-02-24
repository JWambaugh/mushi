#include "ScriptCommand.h"

ScriptCommand::ScriptCommand(QString path)
{
    this->scriptPath = path;
    //load the code, prepare it for execution
    this->scriptCode=getFileContents(path);
    precompileMJS(this->scriptCode);
}
