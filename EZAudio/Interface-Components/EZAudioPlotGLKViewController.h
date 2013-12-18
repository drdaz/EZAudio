//
//  EZAudioPlotGLKViewController.h
//  EZAudioExampleiOS
//
//  Created by Syed Haris Ali on 11/22/13.
//  Copyright (c) 2013 Syed Haris Ali. All rights reserved.
//

#import "TargetConditionals.h"

#if TARGET_OS_IPHONE

#import "EZAudioPlotGL.h"

@class EZAudio;

/**

 */
@interface EZAudioPlotGLKViewController : GLKViewController

#pragma mark - Properties
///-----------------------------------------------------------
/// @name Customizing The Plot's Appearance
///-----------------------------------------------------------
/**
 The default background color of the plot. For iOS the color is specified as a UIColor while for OSX the color is an NSColor. The default value on both platforms is black.
 */
@property (nonatomic,strong) UIColor *backgroundColor;

/**
 *  <#Description#>
 */
@property (nonatomic,strong) GLKBaseEffect *baseEffect;

/**
 The default color of the plot's data (i.e. waveform, y-axis values). For iOS the color is specified as a UIColor while for OSX the color is an NSColor. The default value on both platforms is red.
 */
@property (nonatomic,strong) UIColor *color;

/**
 *  <#Description#>
 */
@property (nonatomic,strong) EAGLContext *context;

/**
 *  <#Description#>
 */
@property (nonatomic,assign) EZAudioPlotGLDrawType drawingType;

/**
 The plot's gain value, which controls the scale of the y-axis values. The default value of the gain is 1.0f and should always be greater than 0.0f.
 */
@property (nonatomic,assign,setter=setGain:) float gain;

/**
 The type of plot as specified by the `SHAPlotType` enumeration (i.e. a buffer or rolling plot type).
 */
@property (nonatomic,assign,setter=setPlotType:) EZPlotType plotType;

/**
 A boolean indicating whether the graph should be rotated along the x-axis to give a mirrored reflection. This is typical for audio plots to produce the classic waveform look. A value of YES will produce a mirrored reflection of the y-values about the x-axis, while a value of NO will only plot the y-values.
 */
@property (nonatomic,assign,setter=setShouldMirror:) BOOL shouldMirror;

#pragma mark - Get Samples
///-----------------------------------------------------------
/// @name Updating The Plot
///-----------------------------------------------------------
/**
 Updates the plot with the new buffer data and tells the view to redraw itself. Caller will provide a float array with the values they expect to see on the y-axis. The plot will internally handle mapping the x-axis and y-axis to the current view port, any interpolation for fills effects, and mirroring.
 @param buffer     A float array of values to map to the y-axis.
 @param bufferSize The size of the float array that will be mapped to the y-axis.
 @warning The bufferSize is expected to be the same, constant value once initial triggered. For plots using OpenGL a vertex buffer object will be allocated with a maximum buffersize of (2 * the initial given buffer size) to account for any interpolation necessary for filling in the graph. Updates use the glBufferSubData(...) function, which will crash if the buffersize exceeds the initial maximum allocated size.
 */
-(void)updateBuffer:(float *)buffer
     withBufferSize:(UInt32)bufferSize;

@end

#elif TARGET_OS_MAC
#endif