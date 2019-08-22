/*
 *          Copyright (c) 1998-2017, Scientific Toolworks, Inc.
 *
 * This file contains proprietary information of Scientific Toolworks, Inc.
 * and is protected by federal copyright law. It may not be copied or
 * distributed in any form or medium without prior written authorization
 * from Scientific Toolworks, Inc.
 *
 */


#ifndef UDB_H_
#define UDB_H_


/*
 * public types
 */

typedef int UdbKind;
typedef struct UdbEntity_    *UdbEntity;
typedef struct UdbKindList_  *UdbKindList;
typedef struct UdbLexeme_    *UdbLexeme;
typedef struct UdbLexer_     *UdbLexer;
typedef struct UdbLibrary_   *UdbLibrary;
typedef struct UdbMetric_    *UdbMetric;
typedef struct UdbReference_ *UdbReference;



/*
 * public enumerations
 */

typedef enum UdbCommentStyle_ {
  Udb_commentStyleDefault = 0,
  Udb_commentStyleAfter   = 1,
  Udb_commentStyleBefore  = 2
} UdbCommentStyle;

typedef enum UdbCommentFormat_ {
  Udb_commentFormatDefault = 0
} UdbCommentFormat;

typedef enum UdbLanguage_ {
  Udb_language_NONE    = 0x0000,
  Udb_language_ALL     = 0x7FFF,
  Udb_language_Ada     = 0x0001,
  Udb_language_Asm     = 0x0002,
  Udb_language_Basic   = 0x0004,
  Udb_language_C       = 0x0008,
  Udb_language_Cobol   = 0x0010,
  Udb_language_CSharp  = 0x0020,
  Udb_language_Fortran = 0x0040,
  Udb_language_Java    = 0x0080,
  Udb_language_Jovial  = 0x0100,
  Udb_language_Pascal  = 0x0200,
  Udb_language_Plm     = 0x0400,
  Udb_language_Python  = 0x0800,
  Udb_language_Vhdl    = 0x2000,
  Udb_language_Web     = 0x4000,
} UdbLanguage;

typedef enum UdbMetricKind_ {
  Udb_mkind_NONE=0,
  Udb_mkind_Integer,
  Udb_mkind_Real
} UdbMetricKind;


typedef enum UdbStatus_ {
  Udb_statusOkay                     = 0,
  Udb_statusDBAlreadyOpen            = 1,
  Udb_statusDBBusy                   = 2, /* not used */
  Udb_statusDBChanged                = 3,
  Udb_statusDBCorrupt                = 4,
  Udb_statusDBOldVersion             = 5,
  Udb_statusDBUnknownVersion         = 6,
  Udb_statusDBUnableCreate           = 7,
  Udb_statusDBUnableDelete           = 8,
  Udb_statusDBUnableModify           = 9,
  Udb_statusDBUnableOpen             = 10,
  Udb_statusDBUnableWrite            = 11,
  Udb_statusDemoAnotherDBOpen        = 12,
  Udb_statusDemoInvalid              = 13,
  Udb_statusDrawNoFont               = 14,
  Udb_statusDrawNoImage              = 15,
  Udb_statusDrawTooBig               = 16,
  Udb_statusDrawUnableCreateFile     = 17,
  Udb_statusDrawUnsupportedFile      = 18,
  Udb_statusLexerFileModified        = 19,
  Udb_statusLexerFileUnreadable      = 20,
  Udb_statusLexerUnsupportedLanguage = 21,
  Udb_statusNoApiLicense             = 22,
  Udb_statusNoApiLicenseAda          = 23,
  Udb_statusNoApiLicenseC            = 24,
  Udb_statusNoApiLicenseCobol        = 25,
  Udb_statusNoApiLicenseFtn          = 26,
  Udb_statusNoApiLicenseJava         = 27,
  Udb_statusNoApiLicenseJovial       = 28,
  Udb_statusNoApiLicensePascal       = 29,
  Udb_statusNoApiLicensePlm          = 30,
  Udb_statusNoApiLicensePython       = 31,
  Udb_statusNoApiLicenseWeb          = 32,
  Udb_statusNoApiLicenseVhdl         = 33,
  Udb_statusNoApiLicenseVerilog      = 34,
  Udb_statusReportUnableCreate       = 35,
  Udb_statusReportUnableDelete       = 36,
  Udb_statusReportUnableWrite        = 37,
  Udb_statusUserAbort                = 38,
  Udb_statusWrongProduct             = 39,
  Udb_status_LAST
} UdbStatus;


typedef enum UdbToken_ {
  Udb_tokenEOF            = 0,
  Udb_tokenComment        = 1,
  Udb_tokenContinuation   = 2,
  Udb_tokenDedent         = 3,
  Udb_tokenEndOfStatement = 4,
  Udb_tokenIdentifier     = 5,
  Udb_tokenIdSeq          = 6,
  Udb_tokenIndent         = 7,
  Udb_tokenKeyword        = 8,
  Udb_tokenLabel          = 9,
  Udb_tokenLiteral        = 10,
  Udb_tokenNewline        = 11,
  Udb_tokenOperator       = 12,
  Udb_tokenPreprocessor   = 13,
  Udb_tokenPunctuation    = 14,
  Udb_tokenString         = 15,
  Udb_tokenWhitespace     = 16,
  Udb_token_LAST
} UdbToken;



/*
 * public functions
 */

#ifdef __cplusplus
extern "C" {
#endif


#if defined (_WIN32) && defined (UDB_API)
#define Export __declspec(dllexport)
#else
#define Export extern
#endif


// Lookup the comments associated with the specified entity and return a
// UTF-8 temporary, formatted string.
Export char const *udbComment(UdbEntity,UdbCommentStyle,UdbCommentFormat,UdbKindList);

// Lookup the comments associated with the specified entity and return a
// UTF-8 temporary array of raw comment strings.
Export void udbCommentRaw(UdbEntity,UdbCommentStyle,UdbKindList,char const * const **,int *);

Export void udbDbClose();

// Return the major language or languages of the current database.
Export UdbLanguage udbDbLanguage();

// Return the list of languages required to open a db. No api license is
// required for this call. Filename is in UTF-8.
Export UdbLanguage udbDbLanguages(char const *filename);

// Return the filename in UTF-8 of the current database as a temporary string.
// Name is in absolute, real-case format. Return 0 if no database is open.
Export char const *udbDbName();

// Open a database. Filename is in UTF-8.
Export UdbStatus udbDbOpen(char const *filename);

// Return the entity id. This is only valid until the db is changed.
Export int udbEntityId(UdbEntity);

// Return the entity kind.
Export UdbKind udbEntityKind(UdbEntity);

// Return the entity language.
Export UdbLanguage udbEntityLanguage(UdbEntity);

// Return the entity library.
Export UdbLibrary udbEntityLibrary(UdbEntity);

// Return the entity long name as a UTF-8 temporary string. If there is no long name
// the short name is returned.
Export char const *udbEntityNameLong(UdbEntity);

// Return the absolute name for file entity as a UTF-8 temporary string.
Export char const *udbEntityNameAbsolute(UdbEntity);

// Return the relative name for file entity as a UTF-8 temporary string.
Export char const *udbEntityNameRelative(UdbEntity);

// Return the entity short name as a UTF-8 temporary string.
Export char const *udbEntityNameShort(UdbEntity);

// Return the entity simple name as a UTF-8 temporary string.
Export char const *udbEntityNameSimple(UdbEntity);

// Return the entity unique name as a UTF-8 temporary string.
Export char const *udbEntityNameUnique(UdbEntity);

// Return true if entity can have parameters. If text is specified return a
// UTF-8 temporary string of parameters prototype. If showname is specified
// include the names of the parameters.
Export int udbEntityParameters(UdbEntity,char const **text,int shownames);

// Return an allocated list of references, using the refkinds and/or
// the entkinds specified. Return the length of list. The list of refs
// must be freed with udbListReferenceFree().
Export int udbEntityRefs(UdbEntity,char const *refkinds,char const *entkinds,int,UdbReference **);

// Return the entity typetext as a UTF-8 temporary string.
Export char const *udbEntityTypetext(UdbEntity);

// Return a UTF-8 temporary string of the value associated with certain
// entities such as enumerators, initialized variables, default parameter
// values in function definitions and macros.
Export char const *udbEntityValue(UdbEntity);

// Return the entity freetext as a UTF-8 temporary string.
Export char const *udbEntityFreetext(UdbEntity,char const *kind);

// Return the current build as a temporary string.
Export char const *udbInfoBuild();

// Return true if the kind matches the kind text.
Export int udbIsKind(UdbKind,char const *);

// Return true if the kind refers to a file entity.
Export int udbIsKindFile(UdbKind);

// Return the inverse of the reference kind.
Export UdbKind udbKindInverse(UdbKind);

// Add a kind to the kindlist if not 0 or allocate a new kindlist.
Export void udbKindList(UdbKind,UdbKindList *);

// Return the language of the kind.
Export UdbLanguage udbKindLanguage(UdbKind);

// Return an allocated copy of kindlist that must be freed with
// udbKindListFree()
Export UdbKindList udbKindListCopy(UdbKindList);

// Free an allocated kindlist.
Export void udbKindListFree(UdbKindList);

// Return true if kind is in the kindlist.
Export int udbKindLocate(UdbKind,UdbKindList);

// Return the long name of kind as a temporary string.
Export char const *udbKindLongname(UdbKind);

// Parse the kind text and return an allocated kindlist that must be freed
// with udbKindListFree().
Export UdbKindList udbKindParse(char const *);

// Return the short name of kind as a temporary string.
Export char const *udbKindShortname(UdbKind);

// Return an array of text representations for a single or multiple language.
// An entity has a single language but a database may have multiple
// languagaes. The returned array is 0 terminated and must be freed with
// udbLanguageStringsFree().
Export char **udbLanguageStrings(UdbLanguage language);

// Free array of languages returned by udbLanguageAsStrings().
Export void udbLanguageStringsFree(char **list);

// Return the lexeme beginning column.
Export int udbLexemeColumnBegin(UdbLexeme);

// Return the lexeme ending column.
Export int udbLexemeColumnEnd(UdbLexeme);

// Return the lexeme associated entity.
Export UdbEntity udbLexemeEntity(UdbLexeme);

// Return true if the lexeme is part of inactive code.
Export int udbLexemeInactive(UdbLexeme);

// Return the lexeme beginning line.
Export int udbLexemeLineBegin(UdbLexeme);

// Return the lexeme ending line.
Export int udbLexemeLineEnd(UdbLexeme);

// Return the next lexeme, or 0 for end.
Export UdbLexeme udbLexemeNext(UdbLexeme);

// Return the previous lexeme, or 0 for beginning.
Export UdbLexeme udbLexemePrevious(UdbLexeme);

// Return the lexeme associated reference, or 0.
Export UdbReference  udbLexemeReference(UdbLexeme);

// Return the lexeme text as a UTF-8 temporary string.
Export char const *udbLexemeText(UdbLexeme);

// Return the lexeme token.
Export UdbToken udbLexemeToken(UdbLexeme);

// Return the name of a lexeme token.
Export char const *udbLexemeTokenName(UdbToken token);

// Delete a lexer and all its lexemes.
Export void udbLexerDelete(UdbLexer);

// Return the first lexeme of the lexer.
Export UdbLexeme udbLexerFirst(UdbLexer);

// Return the lexeme that occurs at the specified line/column.
Export UdbLexeme udbLexerLexeme(UdbLexer,int line,int col);

// Return a temporary array of lexemes within the specified range of lines.
// If no lexeme begins on the starting line, the lexeme that includes the
// starting line will be returned. The returned list is temporary and will be
// made invalid on the next call to this function. Return size of array.
Export int udbLexerLexemes(UdbLexer,int,int,UdbLexeme **);

// Return the number of lines in the specified lexer.
Export int udbLexerLines(UdbLexer);

// Create a lexer for the file entity. The physical source file associated
// with the entity must be readable and must not be changed since the database
// was last updated.
Export UdbStatus udbLexerNew(UdbEntity,int,UdbLexer *);

// Return true if the specified entity is in the specified list of libraries.
Export int udbLibraryCheckEntity(UdbEntity,UdbLibrary *);

// Compare 2 library structures. Return a value suitable for typical
// compare operations (ie, 0=same, <0=lib1<lib2, >0=lib1>lib2).
Export int udbLibraryCompare(UdbLibrary,UdbLibrary);

// Filter the specified list of entities with the specified library
// filter and return a new, allocated list.
Export void udbLibraryFilterEntity(UdbEntity *,char const *,UdbEntity **,int *);

// Return an allocated list of libraries. Use udbLibraryListFree() to
// free the list.
Export void udbLibraryList(char const *,UdbLibrary **,int *);

// Free the allocated library list.
Export void udbLibraryListFree(UdbLibrary *);

// Return the library name as a UTF-8 temporary string.
Export char const *udbLibraryName(UdbLibrary);

// Return a non-allocated, permanent list of all entities. After a database
// update, the list is invalid and must be retrieved again. Ths list may be
// used in places where an allocated entity list is required and may be
// safely passed to udbListEntityFree().
Export void udbListEntity(UdbEntity **,int *);

// Filter the specified list of entities, using the kinds specified, and return
// a new allocated array. Use udbListEntityFree() to free this list. The
// original list of entities and the kindlist must both be allocated and will
// be freed by this call.
Export void udbListEntityFilter(UdbEntity *,UdbKindList,UdbEntity **,int *);

// Free an allocated list of entities.
Export void udbListEntityFree(UdbEntity *);

// Return a temporary list of all analyzed file entities.
Export void udbListFile(UdbEntity **,int *);

// Return allocated list of all entity kinds. Call udbListKindFree() to free
// list.
Export void udbListKindEntity(UdbKind **,int *);

// Free an allocated list of kinds.
Export void udbListKindFree(UdbKind *);

// Return allocated list of all reference kinds. Call udbListKindFree() to
// free list.
Export void udbListKindReference(UdbKind **,int *num);

// Return an allocated list of all references for entity.
// Free the list with udbListReferenceFree().
Export void udbListReference(UdbEntity,UdbReference **,int *num);

// Return an allocated list of all references within file.
// Free the list with udbListReferenceFree().
Export void udbListReferenceFile(UdbEntity,UdbReference **,int *num);

// Filter the specified list of references, using the refkinds and/or the
// entkinds specified, and return a new allocated array. If unique is
// specified, the newrefs array will only contain the first reference for
// each unique entity. Refkinds and Entkinds must both be allocated and
// will be freed by this call.
Export void udbListReferenceFilter(UdbReference *,UdbKindList refkinds,UdbKindList entkinds,
                                   int unique,UdbReference **refs,int *num);

// Free the allocated references list.
Export void udbListReferenceFree(UdbReference *);

// Lookup and return an allocated list of entities by name and kind, if
// specified.
Export void udbLookupEntity(char const *name,char const *kind,int shortname,UdbEntity **ents,int *num);

// Lookup an entity by name and file, line and column where it is referenced.
Export UdbEntity udbLookupEntityByReference(UdbEntity,char const *name,int line,int col,int *matchline);

// Lookup an entity by unique name.
Export UdbEntity udbLookupEntityByUniquename(char const *uniquename);

// Lookup a project file by long or short name.
Export UdbEntity udbLookupFile(char const *);

// Lookup the expansion text for a macro name at a location identified by file,
// line and column. Return true if found, or false if not. Return a UTF-8
// temporary copy of the expansion text. This is only available for C++ files
// with the option "Save macro expansion text" enabled.
Export int udbLookupMacroExpansionText(char const *name,UdbEntity file,int line,int column,char const **text);

// Return true if the specified entity has any reference of the general kind
// specified by the list of references. Return true if the list is 0. Kindlist
// must be allocated and will be deleted.
Export int udbLookupReferenceExists(UdbEntity,UdbKindList kindlist);

// Return the description of the specified metric, as a temporary string.
Export char const *udbMetricDescription(UdbMetric);

// Return the descriptive name of the specified metric, as a temporary string.
Export char const *udbMetricDescriptiveName(UdbMetric);

// Return true if the specified metric is defined for the specified entity.
Export int udbMetricIsDefinedEntity(UdbMetric,UdbEntity);

// Return true if the specified metric is defined as a project metric for the
// specified language.
Export int udbMetricIsDefinedProject(UdbMetric,UdbLanguage);

// Return the value kind of a metric.
Export UdbMetricKind udbMetricKind(UdbMetric);

// Return the size of a temporary, null-terminated list of all metrics defined
// for the specified entity.
Export int udbMetricListEntity(UdbEntity,UdbMetric **);

// Return the size of a temporary, null-terminated list of all metrics defined
// for the specified ent kinds filter.
Export int udbMetricListKind(char const *kinds,UdbMetric **);

// Return the size of a temporary, null-terminated list of all metrics defined
// for the specified language.
Export int udbMetricListLanguage(UdbLanguage,UdbMetric **);

// Return the size of a temporary, null-terminated list of all project metrics
// defined for the specified language.
Export int udbMetricListProject(UdbLanguage,UdbMetric **);

// Lookup a metric by name.
Export UdbMetric udbMetricLookup(char const *);

// Return the name of the specified metric, as a temporary string.
Export char *udbMetricName(UdbMetric);

// Return the value of a metric for the specified entity.
Export double udbMetricValue(UdbEntity,UdbMetric);

// Return the value of a project metric.
Export double udbMetricValueProject(UdbMetric);

// Return reference column.
Export int udbReferenceColumn(UdbReference);

// Return an allocated copy of reference.
Export UdbReference udbReferenceCopy(UdbReference);

// Free reference copied by udbReferenceCopy().
Export void udbReferenceCopyFree(UdbReference);

// Return reference entity.
Export UdbEntity udbReferenceEntity(UdbReference);

// Return reference file.
Export UdbEntity udbReferenceFile(UdbReference);

// Return reference kind.
Export UdbKind udbReferenceKind(UdbReference);

// Return reference line.
Export int udbReferenceLine(UdbReference);

// Return reference scope.
Export UdbEntity udbReferenceScope(UdbReference);

Export void udbSetLicense(char const *dir);
Export char const *udbStatusText(UdbStatus status);


#undef Export

#ifdef __cplusplus
}
#endif


#endif
