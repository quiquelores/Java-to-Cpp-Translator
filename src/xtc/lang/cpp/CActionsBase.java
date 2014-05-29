/*
 * xtc - The eXTensible Compiler
 * Copyright (C) 2009-2012 New York University
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 */
package xtc.lang.cpp;

import xtc.lang.cpp.ForkMergeParser.Subparser;

/**
 * This class is generated from grammar annotations and provides semantic
 * value and action support.
 */
public abstract class CActionsBase extends Actions {

  public ValueType getValueType(int id) {
    if (0 <= id && id < 65) {
      return ValueType.NODE;
    }
    switch (id - 65) {
      case 64: // ExternalDeclarationList (129)
        // Fall through
      case 80: // DeclarationQualifierList (145)
        // Fall through
      case 81: // TypeQualifierList (146)
        // Fall through
      case 108: // StructDeclarationList (173)
        // Fall through
      case 110: // StructDefaultDeclaringList (175)
        // Fall through
      case 111: // StructDeclaringList (176)
        // Fall through
      case 117: // EnumeratorList (182)
        // Fall through
      case 121: // ParameterList (186)
        // Fall through
      case 123: // IdentifierList (188)
        // Fall through
      case 131: // MatchedInitializerList (196)
        // Fall through
      case 133: // DesignatorList (198)
        // Fall through
      case 164: // LocalLabelDeclarationList (229)
        // Fall through
      case 166: // LocalLabelList (231)
        // Fall through
      case 167: // DeclarationOrStatementList (232)
        // Fall through
      case 169: // DeclarationList (234)
        // Fall through
      case 175: // StringLiteralList (240)
        // Fall through
      case 182: // ArgumentExpressionList (247)
        // Fall through
      case 209: // AttributeSpecifierList (274)
        // Fall through
      case 213: // AttributeList (278)
        // Fall through
      case 222: // Assemblyoperands (287)
        return ValueType.LIST;

      case 0: // LPAREN (65)
        // Fall through
      case 1: // RPAREN (66)
        // Fall through
      case 2: // COMMA (67)
        // Fall through
      case 5: // LBRACE (70)
        // Fall through
      case 6: // RBRACE (71)
        // Fall through
      case 7: // LBRACK (72)
        // Fall through
      case 8: // RBRACK (73)
        // Fall through
      case 9: // DOT (74)
        // Fall through
      case 22: // QUESTION (87)
        // Fall through
      case 23: // COLON (88)
        // Fall through
      case 24: // SEMICOLON (89)
        // Fall through
      case 25: // ASSIGN (90)
        return ValueType.LAYOUT;

      case 229: // BindIdentifier (294)
        // Fall through
      case 230: // BindIdentifierInList (295)
        // Fall through
      case 231: // BindVar (296)
        // Fall through
      case 232: // BindEnum (297)
        // Fall through
      case 233: // EnterScope (298)
        // Fall through
      case 234: // ExitScope (299)
        // Fall through
      case 235: // ExitReentrantScope (300)
        // Fall through
      case 236: // ReenterScope (301)
        // Fall through
      case 237: // KillReentrantScope (302)
        return ValueType.ACTION;

      case 63: // TranslationUnit (128)
        // Fall through
      case 65: // ExternalDeclaration (130)
        // Fall through
      case 67: // FunctionDefinitionExtension (132)
        // Fall through
      case 74: // DeclarationExtension (139)
        // Fall through
      case 78: // DeclarationSpecifier (143)
        // Fall through
      case 79: // TypeSpecifier (144)
        // Fall through
      case 128: // DesignatedInitializer (193)
        // Fall through
      case 137: // Declarator (202)
        // Fall through
      case 138: // TypedefDeclarator (203)
        // Fall through
      case 139: // TypedefDeclaratorMain (204)
        // Fall through
      case 143: // ParenTypedefDeclarator (208)
        // Fall through
      case 146: // IdentifierDeclarator (211)
        // Fall through
      case 147: // IdentifierDeclaratorMain (212)
        // Fall through
      case 148: // UnaryIdentifierDeclarator (213)
        // Fall through
      case 150: // ParenIdentifierDeclarator (215)
        // Fall through
      case 160: // Statement (225)
        // Fall through
      case 168: // DeclarationOrStatement (233)
        // Fall through
      case 176: // PrimaryExpression (241)
        // Fall through
      case 180: // PostfixExpression (245)
        // Fall through
      case 183: // UnaryExpression (248)
        // Fall through
      case 191: // CastExpression (256)
        // Fall through
      case 192: // MultiplicativeExpression (257)
        // Fall through
      case 193: // AdditiveExpression (258)
        // Fall through
      case 194: // ShiftExpression (259)
        // Fall through
      case 195: // RelationalExpression (260)
        // Fall through
      case 196: // EqualityExpression (261)
        // Fall through
      case 197: // AndExpression (262)
        // Fall through
      case 198: // ExclusiveOrExpression (263)
        // Fall through
      case 199: // InclusiveOrExpression (264)
        // Fall through
      case 200: // LogicalAndExpression (265)
        // Fall through
      case 201: // LogicalORExpression (266)
        // Fall through
      case 202: // ConditionalExpression (267)
        // Fall through
      case 203: // AssignmentExpression (268)
        // Fall through
      case 205: // ExpressionOpt (270)
        // Fall through
      case 206: // Expression (271)
        // Fall through
      case 207: // ConstantExpression (272)
        return ValueType.PASS_THROUGH;

      default:
        return ValueType.NODE;
    }
  }
  public boolean isComplete(int id) {
    switch(id) {
    case 275: // AttributeSpecifier
      // Fall through
    case 274: // AttributeSpecifierList
      // Fall through
    case 273: // AttributeSpecifierListOpt
      // Fall through
    case 272: // ConstantExpression
      // Fall through
    case 278: // AttributeList
      // Fall through
    case 283: // AssemblyExpressionOpt
      // Fall through
    case 282: // AssemblyExpression
      // Fall through
    case 281: // AssemblyDefinition
      // Fall through
    case 287: // Assemblyoperands
      // Fall through
    case 286: // AssemblyoperandsOpt
      // Fall through
    case 285: // Assemblyargument
      // Fall through
    case 284: // AssemblyStatement
      // Fall through
    case 258: // AdditiveExpression
      // Fall through
    case 259: // ShiftExpression
      // Fall through
    case 256: // CastExpression
      // Fall through
    case 257: // MultiplicativeExpression
      // Fall through
    case 262: // AndExpression
      // Fall through
    case 263: // ExclusiveOrExpression
      // Fall through
    case 260: // RelationalExpression
      // Fall through
    case 261: // EqualityExpression
      // Fall through
    case 266: // LogicalORExpression
      // Fall through
    case 267: // ConditionalExpression
      // Fall through
    case 264: // InclusiveOrExpression
      // Fall through
    case 265: // LogicalAndExpression
      // Fall through
    case 270: // ExpressionOpt
      // Fall through
    case 271: // Expression
      // Fall through
    case 268: // AssignmentExpression
      // Fall through
    case 269: // AssignmentOperator
      // Fall through
    case 288: // Assemblyoperand
      // Fall through
    case 290: // Assemblyclobbers
      // Fall through
    case 294: // BindIdentifier
      // Fall through
    case 295: // BindIdentifierInList
      // Fall through
    case 296: // BindVar
      // Fall through
    case 297: // BindEnum
      // Fall through
    case 298: // EnterScope
      // Fall through
    case 299: // ExitScope
      // Fall through
    case 300: // ExitReentrantScope
      // Fall through
    case 301: // ReenterScope
      // Fall through
    case 302: // KillReentrantScope
      // Fall through
    case 137: // NestedFunctionDeclarator
      // Fall through
    case 136: // NestedFunctionDefinition
      // Fall through
    case 139: // DeclarationExtension
      // Fall through
    case 138: // NestedFunctionOldPrototype
      // Fall through
    case 141: // DefaultDeclaringList
      // Fall through
    case 140: // Declaration
      // Fall through
    case 143: // DeclarationSpecifier
      // Fall through
    case 142: // DeclaringList
      // Fall through
    case 129: // ExternalDeclarationList
      // Fall through
    case 128: // TranslationUnit
      // Fall through
    case 131: // EmptyDefinition
      // Fall through
    case 130: // ExternalDeclaration
      // Fall through
    case 133: // FunctionDefinition
      // Fall through
    case 132: // FunctionDefinitionExtension
      // Fall through
    case 135: // FunctionOldPrototype
      // Fall through
    case 134: // FunctionDeclarator
      // Fall through
    case 153: // BasicDeclarationSpecifier
      // Fall through
    case 154: // BasicTypeSpecifier
      // Fall through
    case 155: // SUEDeclarationSpecifier
      // Fall through
    case 156: // SUETypeSpecifier
      // Fall through
    case 157: // TypedefDeclarationSpecifier
      // Fall through
    case 158: // TypedefTypeSpecifier
      // Fall through
    case 159: // TypeofDeclarationSpecifier
      // Fall through
    case 144: // TypeSpecifier
      // Fall through
    case 145: // DeclarationQualifierList
      // Fall through
    case 146: // TypeQualifierList
      // Fall through
    case 171: // StructOrUnionSpecifier
      // Fall through
    case 170: // ElaboratedTypeName
      // Fall through
    case 175: // StructDefaultDeclaringList
      // Fall through
    case 174: // StructDeclaration
      // Fall through
    case 173: // StructDeclarationList
      // Fall through
    case 162: // Typeofkeyword
      // Fall through
    case 161: // Typeofspecifier
      // Fall through
    case 160: // TypeofTypeSpecifier
      // Fall through
    case 186: // ParameterList
      // Fall through
    case 187: // ParameterDeclaration
      // Fall through
    case 184: // EnumeratorValueOpt
      // Fall through
    case 185: // ParameterTypeList
      // Fall through
    case 190: // IdentifierOrTypedefName
      // Fall through
    case 191: // TypeName
      // Fall through
    case 188: // IdentifierList
      // Fall through
    case 189: // Identifier
      // Fall through
    case 178: // StructIdentifierDeclarator
      // Fall through
    case 179: // BitFieldSizeOpt
      // Fall through
    case 176: // StructDeclaringList
      // Fall through
    case 177: // StructDeclarator
      // Fall through
    case 182: // EnumeratorList
      // Fall through
    case 183: // Enumerator
      // Fall through
    case 180: // BitFieldSize
      // Fall through
    case 181: // EnumSpecifier
      // Fall through
    case 205: // ParameterTypedefDeclarator
      // Fall through
    case 204: // TypedefDeclaratorMain
      // Fall through
    case 207: // CleanPostfixTypedefDeclarator
      // Fall through
    case 206: // CleanTypedefDeclarator
      // Fall through
    case 201: // ObsoleteFieldDesignation
      // Fall through
    case 200: // ObsoleteArrayDesignation
      // Fall through
    case 203: // TypedefDeclarator
      // Fall through
    case 202: // Declarator
      // Fall through
    case 196: // MatchedInitializerList
      // Fall through
    case 198: // DesignatorList
      // Fall through
    case 193: // DesignatedInitializer
      // Fall through
    case 192: // InitializerOpt
      // Fall through
    case 195: // InitializerList
      // Fall through
    case 194: // Initializer
      // Fall through
    case 220: // PostfixingAbstractDeclarator
      // Fall through
    case 221: // ParameterTypeListOpt
      // Fall through
    case 222: // ArrayAbstractDeclarator
      // Fall through
    case 223: // UnaryAbstractDeclarator
      // Fall through
    case 216: // SimpleDeclarator
      // Fall through
    case 217: // OldFunctionDeclarator
      // Fall through
    case 218: // PostfixOldFunctionDeclarator
      // Fall through
    case 219: // AbstractDeclarator
      // Fall through
    case 212: // IdentifierDeclaratorMain
      // Fall through
    case 213: // UnaryIdentifierDeclarator
      // Fall through
    case 214: // PostfixIdentifierDeclarator
      // Fall through
    case 215: // ParenIdentifierDeclarator
      // Fall through
    case 208: // ParenTypedefDeclarator
      // Fall through
    case 209: // ParenPostfixTypedefDeclarator
      // Fall through
    case 210: // SimpleParenTypedefDeclarator
      // Fall through
    case 211: // IdentifierDeclarator
      // Fall through
    case 239: // Constant
      // Fall through
    case 238: // JumpStatement
      // Fall through
    case 237: // IterationStatement
      // Fall through
    case 236: // SelectionStatement
      // Fall through
    case 235: // ExpressionStatement
      // Fall through
    case 234: // DeclarationList
      // Fall through
    case 233: // DeclarationOrStatement
      // Fall through
    case 232: // DeclarationOrStatementList
      // Fall through
    case 231: // LocalLabelList
      // Fall through
    case 230: // LocalLabelDeclaration
      // Fall through
    case 229: // LocalLabelDeclarationList
      // Fall through
    case 228: // LocalLabelDeclarationListOpt
      // Fall through
    case 227: // CompoundStatement
      // Fall through
    case 226: // LabeledStatement
      // Fall through
    case 225: // Statement
      // Fall through
    case 224: // PostfixAbstractDeclarator
      // Fall through
    case 254: // LabelAddressExpression
      // Fall through
    case 252: // AlignofExpression
      // Fall through
    case 250: // OffsetofExpression
      // Fall through
    case 251: // ExtensionExpression
      // Fall through
    case 248: // UnaryExpression
      // Fall through
    case 249: // TypeCompatibilityExpression
      // Fall through
    case 246: // CompoundLiteral
      // Fall through
    case 247: // ArgumentExpressionList
      // Fall through
    case 244: // StatementAsExpression
      // Fall through
    case 245: // PostfixExpression
      // Fall through
    case 242: // PrimaryIdentifier
      // Fall through
    case 243: // VariableArgumentAccess
      // Fall through
    case 240: // StringLiteralList
      // Fall through
    case 241: // PrimaryExpression
      return true;

    default:
      return false;
    }
  }

  public void dispatch(int id, Subparser subparser) {
    switch(id) {
    case 294:
      BindIdentifier(subparser);
      break;

    case 295:
      BindIdentifierInList(subparser);
      break;

    case 296:
      BindVar(subparser);
      break;

    case 297:
      BindEnum(subparser);
      break;

    case 298:
      EnterScope(subparser);
      break;

    case 299:
      ExitScope(subparser);
      break;

    case 300:
      ExitReentrantScope(subparser);
      break;

    case 301:
      ReenterScope(subparser);
      break;

    case 302:
      KillReentrantScope(subparser);
      break;

    default:
      // Do nothing
      break;
    }
  }

  public abstract void BindIdentifier(Subparser subparser);

  public abstract void BindIdentifierInList(Subparser subparser);

  public abstract void BindVar(Subparser subparser);

  public abstract void BindEnum(Subparser subparser);

  public abstract void EnterScope(Subparser subparser);

  public abstract void ExitScope(Subparser subparser);

  public abstract void ExitReentrantScope(Subparser subparser);

  public abstract void ReenterScope(Subparser subparser);

  public abstract void KillReentrantScope(Subparser subparser);

}
