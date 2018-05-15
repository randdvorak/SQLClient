#  SQLClient - Native Microsoft SQL Server client updated to allow stored procedure calls

## Microsoft SQL Server does not return out parameters unless a call is made using dbrpcsend, this library remedies that

### Library dependencies:   sybdb, iconv, crypto, ssl (ssl lib must support tls if using freetds)


#### Remote procedure call parameter format:  An NSArray of NSDictionary where the key for the single value dict is  "<param name>  "out"- (optional, "in" is assumed if value present, NSNull if passing null or only an out parameter) <type specifier>"
#### The following types specifiers are supported:
#####                                %s - NString passed as char, varchar
#####                                %d  - NSNumber passed as int
#####                                %f  - NSNumber passed as float
#####                                %b - NSNumber passed as bit
#####                                %D - NSDate passed as datetimeas
#####                                %B - NSData passed as binary data

