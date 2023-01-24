##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ErathostenesSucc3
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=A:/FTP/M2/Algos_et_Structs
ProjectPath            :=A:/FTP/M2/Algos_et_Structs/Eratho2/5IN0301-2/exercices/ErathostenesSucc3
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Hean
Date                   :=13/11/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/ProgramData/chocolatey/lib/mingw/tools/install/mingw64/bin/g++.exe
SharedObjectLinkerName :=C:/ProgramData/chocolatey/lib/mingw/tools/install/mingw64/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="ErathostenesSucc3.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/ProgramData/chocolatey/lib/mingw/tools/install/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)./../../syllabus/InOut/src $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)InOut 
ArLibs                 :=  "InOut" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./../../syllabus/InOut/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/ProgramData/chocolatey/lib/mingw/tools/install/mingw64/bin/ar.exe rcu
CXX      := C:/ProgramData/chocolatey/lib/mingw/tools/install/mingw64/bin/g++.exe
CC       := C:/ProgramData/chocolatey/lib/mingw/tools/install/mingw64/bin/gcc.exe
CXXFLAGS := -std=c++17 -pedantic-errors -Wall -g -O0 $(Preprocessors)
CFLAGS   := -std=c90 -pedantic-errors -Wall -g -O0 $(Preprocessors)
ASFLAGS  := 
AS       := C:/ProgramData/chocolatey/lib/mingw/tools/install/mingw64/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_ErathostenesSucc3.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_ErathostenesSucc3.cpp$(ObjectSuffix): src/ErathostenesSucc3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_ErathostenesSucc3.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_ErathostenesSucc3.cpp$(DependSuffix) -MM src/ErathostenesSucc3.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "A:/FTP/M2/Algos_et_Structs/Eratho2/5IN0301-2/exercices/ErathostenesSucc3/src/ErathostenesSucc3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_ErathostenesSucc3.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_ErathostenesSucc3.cpp$(PreprocessSuffix): src/ErathostenesSucc3.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_ErathostenesSucc3.cpp$(PreprocessSuffix) src/ErathostenesSucc3.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


