##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=PolyDemo
ConfigurationName      :=Release
WorkspacePath          :=D:/users/jean/Documents/Ann_2223/isib/cpp/5IN0301/workspace
ProjectPath            :=D:/users/jean/Documents/Ann_2223/isib/cpp/5IN0301/syllabus/PolyDemo
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=moulinjean
Date                   :=13/09/2022
CodeLitePath           :="C:/Program Files (x86)/CodeLite"
LinkerName             :=C:/mingw-w64/i686-12.2.0-release-posix-dwarf-rt_v10-rev0/mingw32/bin/g++.exe
SharedObjectLinkerName :=C:/mingw-w64/i686-12.2.0-release-posix-dwarf-rt_v10-rev0/mingw32/bin/g++.exe -shared -fPIC
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
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="PolyDemo.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/mingw-w64/i686-12.2.0-release-posix-dwarf-rt_v10-rev0/mingw32/bin/windres.exe
LinkOptions            :=  -O2
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)./../InOut/src $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)InOut 
ArLibs                 :=  "InOut" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./../InOut/Release 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/mingw-w64/i686-12.2.0-release-posix-dwarf-rt_v10-rev0/mingw32/bin/ar.exe rcu
CXX      := C:/mingw-w64/i686-12.2.0-release-posix-dwarf-rt_v10-rev0/mingw32/bin/g++.exe
CC       := C:/mingw-w64/i686-12.2.0-release-posix-dwarf-rt_v10-rev0/mingw32/bin/gcc.exe
CXXFLAGS := -std=c++17 -pedantic-errors -Wall -O3 $(Preprocessors)
CFLAGS   := -std=c90 -pedantic-errors -Wall -O3 $(Preprocessors)
ASFLAGS  := 
AS       := C:/mingw-w64/i686-12.2.0-release-posix-dwarf-rt_v10-rev0/mingw32/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
Objects0=$(IntermediateDirectory)/src_PolyDemo.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_poly.cpp$(ObjectSuffix) 



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
	@$(MakeDirCommand) "./Release"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Release"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_PolyDemo.cpp$(ObjectSuffix): src/PolyDemo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_PolyDemo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_PolyDemo.cpp$(DependSuffix) -MM src/PolyDemo.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/users/jean/Documents/Ann_2223/isib/cpp/5IN0301/syllabus/PolyDemo/src/PolyDemo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_PolyDemo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_PolyDemo.cpp$(PreprocessSuffix): src/PolyDemo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_PolyDemo.cpp$(PreprocessSuffix) src/PolyDemo.cpp

$(IntermediateDirectory)/src_poly.cpp$(ObjectSuffix): src/poly.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_poly.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_poly.cpp$(DependSuffix) -MM src/poly.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/users/jean/Documents/Ann_2223/isib/cpp/5IN0301/syllabus/PolyDemo/src/poly.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_poly.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_poly.cpp$(PreprocessSuffix): src/poly.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_poly.cpp$(PreprocessSuffix) src/poly.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Release/


