//
//  ViewController.m
//  iLamp
//
//  Created by Dani Arnaout on 6/19/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController
@synthesize myWebView;

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
}

- (void)viewDidUnload
{
    [self setMyWebView:nil];
    [super viewDidUnload];
    // Release any retained subviews of the main view.
}

- (BOOL)shouldAutorotateToInterfaceOrientation:(UIInterfaceOrientation)interfaceOrientation
{
    return (interfaceOrientation != UIInterfaceOrientationPortraitUpsideDown);
}
- (IBAction)switchPressed:(id)sender 
{
    UISwitch *theSwitch = (UISwitch *) sender;
    
    if (theSwitch.isOn)
    {
        // turn the LED on
        NSURL *url = [NSURL URLWithString:@"http://10.0.0.25/$1"];
        NSURLRequest *req = [NSURLRequest requestWithURL:url];
        [myWebView loadRequest:req];
    }
    else 
    {
        // turn the LED off
        NSURL *url = [NSURL URLWithString:@"http://10.0.0.25/$2"];
        NSURLRequest *req = [NSURLRequest requestWithURL:url];
        [myWebView loadRequest:req];
    }
}

@end
