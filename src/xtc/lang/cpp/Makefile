# Makefile 2 
#***************************************************************************
# 
# Java development root directory.
# 
# (C) 1999 Jacob Dreyer - Geotechnical Software Services
# jacob.dreyer@geosoft.no - http://geosoft.no
#
# Modifications Copyright (C) 2001, 2004 Robert Grimm 
# rgrimm@alum.mit.edu
#
# Modifications Copyright (C) 2007 New York University
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
#
#***************************************************************************




#***************************************************************************
#
# This section describes the current package.
#
# o PACKAGE     - The complete package name. 
# o PACKAGE_LOC - Same as PACKAGE but with "/"s instead of "."s.
# o SOURCE      - List of the source files. Remember extension.
# o JNI_SOURCE  - Files from SOURCE that are to be built with the JAVAH 
#                 compiler.
# o JAR_EXTRAS  - None-class files and directories that are to be bundled
#                 into the jar archive.
#
#***************************************************************************

PACKAGE     = xtc.lang.cpp
PACKAGE_LOC = xtc/lang/cpp

SOURCE = \
	BuiltinsGenerator.java \
	Builtins.java \
	ForkMergeParserTables.java \
	PresenceConditionManager.java \
	Syntax.java \
	CTag.java \
	CLexer.java \
	ConditionParser.java \
	Stream.java \
	CLexerStream.java \
	DirectiveParser.java \
	HeaderFileManager.java \
	MacroTable.java \
	ConditionEvaluator.java \
	CTokenCreator.java \
	Preprocessor.java \
	Actions.java \
	ActionGenerator.java \
	CActionsBase.java \
	CActions.java \
	CParsingContext.java \
	ForkMergeParser.java \
	TokenFilter.java \
	FilenameService.java \
	StreamTimer.java \
	StopWatch.java \
	cdiff.java \
	GCCShunt.java \
	SuperC.java


JNI_SOURCE =

JAR_EXTRAS =


#***************************************************************************
#
# Include common part of makefile
#
#***************************************************************************

ifdef JAVA_DEV_ROOT
include $(JAVA_DEV_ROOT)/Makerules

manual: manual.pdf

manual.pdf: manual.tex
	pdflatex manual.tex
	pdflatex manual.tex
	pdflatex manual.tex

configure:
	if [ -f Builtins.java ]; then $(RM) Builtins.java; fi
	$(MAKE) BuiltinsGenerator.class
	$(MAKE) Builtins.java
	$(MAKE) Builtins.class
	if [ -f ${JAVA_DEV_ROOT}/classes/xtc/lang/cpp/SuperC.class ]; then $(RM) ${JAVA_DEV_ROOT}/classes/xtc/lang/cpp/SuperC.class; $(MAKE) SuperC.class; fi

Builtins.java:
	$(CPP) $(CPPFLAGS) -v empty.c 2> sysdirs > /dev/null
	$(CPP) $(CPPFLAGS) -dM empty.c > builtins 2> /dev/null
	$(JAVA) xtc.lang.cpp.BuiltinsGenerator sysdirs builtins > Builtins.java
	$(RM) sysdirs
	$(RM) builtins

parsers:
	@# parsing tables
	bison -o c.tab.c c.y
	$(CC) $(CFLAGS) -DYYDEBUG -DYYPRINT\(a,b,c\) -o gen_tables gen_tables.c
	./gen_tables > ForkMergeParserTables.java
	$(RM) gen_tables
	$(MAKE) ForkMergeParserTables.class
	@# C lexer and token tags
	$(CPP) $(CPPFLAGS) -DTAG - < c.l | grep -v "^#" > CTag.java
	$(MAKE) CTag.class
	@# lexer
	@#   filter out line directives for java compilation
	$(CPP) $(CPPFLAGS) -DLEXER - < c.l | grep -v "^#" > c.l.lexer
	$(JAVA) -jar $(JAVA_DEV_ROOT)/bin/JFlex.jar c.l.lexer
	$(RM) c.l.lexer
	$(MAKE) CLexer.class
	@# semantic actions
	$(MAKE) ActionGenerator.class
	./gen_actions.pl < c.y | $(JAVA) xtc.lang.cpp.ActionGenerator CActionsBase > CActionsBase.java
	$(MAKE) CActionsBase.class
	$(RATS) -option 'parser(xtc.lang.cpp.ConditionParser)' Condition.rats
	$(MAKE) ConditionParser.class
	$(RM) ${JAVA_DEV_ROOT}/classes/xtc/lang/cpp/ForkMergeParser.class
	$(MAKE) ForkMergeParser.class

clobber-parsers :
	$(RM) CLexer.java
	$(RM) c.tab.c
	$(RM) ForkMergeParserTables.java
	$(RM) CActionsBase.java
	$(RM) ConditionParser.java

endif
