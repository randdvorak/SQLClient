//
//  SQLClient.h
//  SQLClient
//
//  Created by Martin Rybak on 10/4/13.
//  Copyright (c) 2013 Martin Rybak. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* _Nonnull const SQLClientMessageNotification;
extern NSString* _Nonnull const SQLClientErrorNotification;
extern NSString* _Nonnull const SQLClientMessageKey;
extern NSString* _Nonnull const SQLClientCodeKey;
extern NSString* _Nonnull const SQLClientSeverityKey;

/**
 *  Native SQL Server client for iOS. An Objective-C wrapper around the open-source FreeTDS library.
 */
@interface SQLClient : NSObject

/**
 *  Connection timeout, in seconds. Default is 5. Set before calling connect.
 */
@property (nonatomic, assign) int timeout;

/**
 *  The character set to use for converting the UCS-2 server results. Default is UTF-8.
 *  Set before calling connect. Can be set to any charset supported by the iconv library.
 *  To list all supported iconv character sets, open a Terminal window and enter:
 $  iconv --list
 */
@property (nonatomic, copy, nonnull) NSString* charset;

/**
 *  The maximum length of a string in a query is configured on the server via the SET TEXTSIZE command.
 *  To find out your current setting, execute SELECT @@TEXTSIZE. SQLClient uses 4096 by default.
 *  To override this setting, update this property.
 */
@property (atomic, assign) int maxTextSize;

/**
 *  Returns an initialized SQLClient instance as a singleton.
 *
 *  @return Shared SQLClient object
 */
+ (nullable instancetype)sharedInstance;

/**
 *  Connects to a SQL database server.
 *
 *  @param host     Required. The database server, i.e. server, server:port, or server\instance (be sure to escape the backslash)
 *  @param username Required. The database username
 *  @param password Required. The database password
 *  @param database Optional. The database name
 */
- (void)connect:(nonnull NSString*)host
       username:(nonnull NSString*)username
       password:(nonnull NSString*)password
       database:(nullable NSString*)database;

/**
 *  Indicates whether the database is currently connected.
 */
- (BOOL)isConnected;

/**
 *  Indicates whether the database is executing a command.
 */
- (BOOL)isExecuting;

/**
 *  Executes a SQL statement. Results of queries will be passed to the completion handler. Inserts, updates, and deletes do not return results.
 *
 *  @param sql Required. A SQL statement
 *  Each row is an NSDictionary of columns where key = name and object = value as one of the following types:
 *  NSString, NSNumber, NSDecimalNumber, NSData, UIImage, NSDate, NSUUID
 */
- (NSArray*_Nullable)execute:(NSString  * _Nonnull)sql;

/**
*   Executes a SQL stored procedure - SQL Server only returns output parameters with an rpc call
*
*  @param procedure Required.  The procedure name
*  @param args Optional.  Procedure parameters, an array of NSDictionarya where key = param name plus a space and ("in", "out", or "in out") then another space and a type format and
*   value = param value, output only params should contain NSNull. Valid values are NSString, NSNumber, NSData and NSDate
*   Type format string to parse procedure parameters are "%s","%d","%f","%b","%D"
*         %s - parse string parameter
*         %d - parse int parameter
*         %f - parse float parameter
*         %b - parse bit parameter
*         %D - parse date parameter
*         %B - parse binary parameter
*
*  Each row is an NSDictionary of columns where key = name and object = value as one of the following types:
*  NSString, NSNumber, NSDecimalNumber, NSData, UIImage, NSDate, NSUUID
*
**/
- (NSArray* _Nullable)call:(NSString* _Nonnull)procedure withArguments:(NSArray* _Nullable)args;
 
 /**
 *  Disconnects from database server.
 */
- (void)disconnect;

- (void)raiseExceptionWithName:(NSString* _Nonnull)name andReason:(NSString* _Nonnull)reason;
@end
