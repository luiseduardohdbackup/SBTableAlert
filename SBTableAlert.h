//
//  SBTableAlert.h
//  SBTableAlert
//
//  Created by Simon Blommegård on 2011-04-08.
//  Copyright 2011 Simon Blommegård. All rights reserved.
//

#import <Foundation/Foundation.h>

@class SBTableAlert;

@protocol SBTableAlertDelegate <NSObject>
@optional

- (void)tableAlert:(SBTableAlert *)tableAlert didSelectRow:(NSInteger)row;
- (void)tableAlertCancel:(SBTableAlert *)tableAlert;

- (void)tableAlert:(SBTableAlert *)tableAlert clickedButtonAtIndex:(NSInteger)buttonIndex;

- (void)willPresentTableAlert:(SBTableAlert *)tableAlert;
- (void)didPresentTableAlert:(SBTableAlert *)tableAlert;

- (void)tableAlert:(SBTableAlert *)tableAlert willDismissWithButtonIndex:(NSInteger)buttonIndex;
- (void)tableAlert:(SBTableAlert *)tableAlert didDismissWithButtonIndex:(NSInteger)buttonIndex;

@end


@protocol SBTableAlertDataSource <NSObject>
@required

- (UITableViewCell *)tableAlert:(SBTableAlert *)tableAlert cellForRow:(NSInteger)row;
- (NSInteger)numberOfRowsInTableAlert:(SBTableAlert *)tableAlert;

@end

#define kNumMaximumVisibleRowsInTableView 4
#define kDefaultRowHeight 40.0
#define kTableCornerRadius 5

typedef enum {
	SBTableAlertTypeSingleSelect, // dismiss alert with button index -1 and animated (default)
	SBTableAlertTypeMultipleSelct, // dismiss handled by user eg. [alert.view dismiss...];
} SBTableAlertType;

@interface SBTableAlert : NSObject <UITableViewDelegate, UITableViewDataSource, UIAlertViewDelegate> {
	UIAlertView *_alertView;
	UITableView *_tableView;
	
	SBTableAlertType _type;
	
	id <SBTableAlertDelegate> _delegate;
	id <SBTableAlertDataSource> _dataSource;
}

@property (nonatomic, retain) UIAlertView *view;
@property (nonatomic, retain) UITableView *tableView;
@property (nonatomic) SBTableAlertType type;

@property (nonatomic, assign) id <SBTableAlertDelegate> delegate;
@property (nonatomic, assign) id <SBTableAlertDataSource> dataSource;

- (id)initWithTitle:(NSString *)title cancelButtonTitle:(NSString *)cancelTitle messageFormat:(NSString *)message, ...;

- (void)show;

@end
