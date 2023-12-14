#import <Foundation/Foundation.h>
#include <Foundation/Foundation.h>

int main() {
  const char *cString = "Hello, World!";
  NSString *objcString = [[NSString alloc] initWithUTF8String:cString];
  NSLog(@"%@", objcString);
  return 0;
}