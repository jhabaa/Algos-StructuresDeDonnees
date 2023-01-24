##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Graph
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=D:/NovBack/Desktop/Algos_et_Structs
ProjectPath            :=D:/NovBack/Desktop/Algos_et_Structs/5IN0301/exercices/Graph
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Hean
Date                   :=24/01/2023
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
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
ObjectsFileList        :="Graph.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). $(IncludeSwitch)..\syllabus\MatrixDemo 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS := -std=c++17 -pedantic-errors -Wall -g -O0 $(Preprocessors)
CFLAGS   := -std=c90 -pedantic-errors -Wall -g,-O0 $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_GraphTest.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_graph.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/src_GraphTest.cpp$(ObjectSuffix): src/GraphTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_GraphTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_GraphTest.cpp$(DependSuffix) -MM src/GraphTest.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/NovBack/Desktop/Algos_et_Structs/5IN0301/exercices/Graph/src/GraphTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_GraphTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_GraphTest.cpp$(PreprocessSuffix): src/GraphTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_GraphTest.cpp$(PreprocessSuffix) src/GraphTest.cpp

$(IntermediateDirectory)/src_graph.cpp$(ObjectSuffix): src/graph.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_graph.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_graph.cpp$(DependSuffix) -MM src/graph.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/NovBack/Desktop/Algos_et_Structs/5IN0301/exercices/Graph/src/graph.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_graph.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_graph.cpp$(PreprocessSuffix): src/graph.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_graph.cpp$(PreprocessSuffix) src/graph.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


