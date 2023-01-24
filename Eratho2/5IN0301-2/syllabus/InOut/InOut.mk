##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=InOut
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=A:/FTP/M2/Algos_et_Structs
ProjectPath            :=A:/FTP/M2/Algos_et_Structs/5IN0301/syllabus/InOut
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Hean
Date                   :=28/09/2022
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
OutputFile             :=$(IntermediateDirectory)/lib$(ProjectName).a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="InOut.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/ProgramData/chocolatey/lib/mingw/tools/install/mingw64/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

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
Objects0=$(IntermediateDirectory)/src_inout.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList)
	@$(MakeDirCommand) "A:\FTP\M2\Algos_et_Structs/.build-debug"
	@echo rebuilt > "A:\FTP\M2\Algos_et_Structs/.build-debug/InOut"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_inout.cpp$(ObjectSuffix): src/inout.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_inout.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_inout.cpp$(DependSuffix) -MM src/inout.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "A:/FTP/M2/Algos_et_Structs/5IN0301/syllabus/InOut/src/inout.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_inout.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_inout.cpp$(PreprocessSuffix): src/inout.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_inout.cpp$(PreprocessSuffix) src/inout.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


