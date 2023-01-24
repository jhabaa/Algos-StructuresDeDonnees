##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=MatrixDemo
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/Users/jean-hubert/Documents/M2/Algos_et_Structs
ProjectPath            :=/Volumes/M2/Algos_et_Structs/5IN0301/syllabus/MatrixDemo
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Jean Hubert ABA'A
Date                   :=13/11/2022
CodeLitePath           :="/Users/jean-hubert/Library/Application Support/CodeLite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -dynamiclib -fPIC
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
ObjectsFileList        :="MatrixDemo.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./../InOut/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -std=c++17 -pedantic-errors -Wall -g -O0 $(Preprocessors)
CFLAGS   := -std=c90 -pedantic-errors -Wall -g:-O0 $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/Applications/codelite.app/Contents/SharedSupport/
Objects0=$(IntermediateDirectory)/src_MatrixDemo.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_Matrix.cpp$(ObjectSuffix) 



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
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_MatrixDemo.cpp$(ObjectSuffix): src/MatrixDemo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_MatrixDemo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_MatrixDemo.cpp$(DependSuffix) -MM src/MatrixDemo.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/M2/Algos_et_Structs/5IN0301/syllabus/MatrixDemo/src/MatrixDemo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_MatrixDemo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_MatrixDemo.cpp$(PreprocessSuffix): src/MatrixDemo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_MatrixDemo.cpp$(PreprocessSuffix) src/MatrixDemo.cpp

$(IntermediateDirectory)/src_Matrix.cpp$(ObjectSuffix): src/Matrix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Matrix.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Matrix.cpp$(DependSuffix) -MM src/Matrix.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/Volumes/M2/Algos_et_Structs/5IN0301/syllabus/MatrixDemo/src/Matrix.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Matrix.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Matrix.cpp$(PreprocessSuffix): src/Matrix.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Matrix.cpp$(PreprocessSuffix) src/Matrix.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


