// Copyright (C) 2002-2007 Nikolaus Gebhardt
// This file is part of the "Irrlicht Engine".
// For conditions of distribution and use, see copyright notice in irrlicht.h

#include "CGUISkin.h"
#include "IGUIFont.h"
#include "IGUISpriteBank.h"
#include "IVideoDriver.h"
#include "IAttributes.h"
#include "SoftwareDriver2_helper.h"

namespace irr
{
namespace gui
{

CGUISkin::CGUISkin(EGUI_SKIN_TYPE type, video::IVideoDriver* driver)
: SpriteBank(0), Driver(driver), Type(type)
{
	#ifdef _DEBUG
	setDebugName("CGUISkin");
	#endif

	if (	(Type == EGST_WINDOWS_CLASSIC) |
			(Type == EGST_WINDOWS_METALLIC)
		)
	{
		Colors[EGDC_3D_DARK_SHADOW]   = video::SColor(101,50,50,50);
		Colors[EGDC_3D_SHADOW]        = video::SColor(101,130,130,130);
		Colors[EGDC_3D_FACE]          = video::SColor(101,210,210,210);
		Colors[EGDC_3D_HIGH_LIGHT]    = video::SColor(101,255,255,255);
		Colors[EGDC_3D_LIGHT]         =	video::SColor(101,210,210,210);
		Colors[EGDC_ACTIVE_BORDER]    = video::SColor(101,16,14,115);
		Colors[EGDC_ACTIVE_CAPTION]   = video::SColor(200,255,255,255);
		Colors[EGDC_APP_WORKSPACE]    = video::SColor(101,100,100,100);
		Colors[EGDC_BUTTON_TEXT]      = video::SColor(240,10,10,10);
		Colors[EGDC_GRAY_TEXT]        = video::SColor(240,130,130,130);
		Colors[EGDC_HIGH_LIGHT]       = video::SColor(101,8,36,107);
		Colors[EGDC_HIGH_LIGHT_TEXT]  = video::SColor(240,255,255,255);
		Colors[EGDC_INACTIVE_BORDER]  = video::SColor(101,165,165,165);
		Colors[EGDC_INACTIVE_CAPTION] = video::SColor(101,210,210,210);
		Colors[EGDC_TOOLTIP]          = video::SColor(200,0,0,0);
		Colors[EGDC_TOOLTIP_BACKGROUND]= video::SColor(200,255,255,225);
		Colors[EGDC_SCROLLBAR]        = video::SColor(101,230,230,230);
		Colors[EGDC_WINDOW]           = video::SColor(101,255,255,255);
		Colors[EGDC_WINDOW_SYMBOL]    = video::SColor(200,10,10,10);
		Colors[EGDC_ICON]             = video::SColor(200,255,255,255);
		Colors[EGDC_ICON_HIGH_LIGHT]  = video::SColor(200,8,36,107);

		Sizes[EGDS_SCROLLBAR_SIZE] = 14;
		Sizes[EGDS_MENU_HEIGHT] = 30;
		Sizes[EGDS_WINDOW_BUTTON_WIDTH] = 15;
		Sizes[EGDS_CHECK_BOX_WIDTH] = 18;
		Sizes[EGDS_MESSAGE_BOX_WIDTH] = 500;
		Sizes[EGDS_MESSAGE_BOX_HEIGHT] = 200;
		Sizes[EGDS_BUTTON_WIDTH] = 80;
		Sizes[EGDS_BUTTON_HEIGHT] = 30;
	
		Sizes[EGDS_TEXT_DISTANCE_X] = 2;
		Sizes[EGDS_TEXT_DISTANCE_Y] = 0;

	}
	else
	{
		//0x80a6a8af
		Colors[EGDC_3D_DARK_SHADOW] =	0x60767982;
		//Colors[EGDC_3D_FACE]		=	0xc0c9ccd4;		// tab background
		Colors[EGDC_3D_FACE]		=	0xc0cbd2d9;		// tab background
		Colors[EGDC_3D_SHADOW]		=	0x50e4e8f1;		// tab background, and left-top highlight
		Colors[EGDC_3D_HIGH_LIGHT]	=	0x40c7ccdc;	
		Colors[EGDC_3D_LIGHT]		=	0x802e313a;
		Colors[EGDC_ACTIVE_BORDER]	=	0x80404040;		// window title
		Colors[EGDC_ACTIVE_CAPTION] =	0xf0d0d0d0;
		Colors[EGDC_APP_WORKSPACE]	=	0xc0646464;		// unused
		Colors[EGDC_BUTTON_TEXT]	=	0xd0161616;
		Colors[EGDC_GRAY_TEXT]		=	0x3c141414;
		Colors[EGDC_HIGH_LIGHT]		=	0x6c606060;
		Colors[EGDC_HIGH_LIGHT_TEXT]=	0xd0e0e0e0;
		Colors[EGDC_INACTIVE_BORDER]=	0xf0a5a5a5;
		Colors[EGDC_INACTIVE_CAPTION]=	0xf0d2d2d2;
		Colors[EGDC_TOOLTIP]		=	0xf00f2033;
		Colors[EGDC_TOOLTIP_BACKGROUND]=0xc0cbd2d9;
		Colors[EGDC_SCROLLBAR]		=	0xf0e0e0e0;
		Colors[EGDC_WINDOW]			=	0xf0f0f0f0;
		Colors[EGDC_WINDOW_SYMBOL]	=	0xd0161616;
		Colors[EGDC_ICON]			=	0xd0161616;
		Colors[EGDC_ICON_HIGH_LIGHT]=	0xd0606060;

		Sizes[EGDS_SCROLLBAR_SIZE] = 14;
		Sizes[EGDS_MENU_HEIGHT] = 48;
		Sizes[EGDS_WINDOW_BUTTON_WIDTH] = 15;
		Sizes[EGDS_CHECK_BOX_WIDTH] = 18;
		Sizes[EGDS_MESSAGE_BOX_WIDTH] = 500;
		Sizes[EGDS_MESSAGE_BOX_HEIGHT] = 200;
		Sizes[EGDS_BUTTON_WIDTH] = 80;
		Sizes[EGDS_BUTTON_HEIGHT] = 30;

		Sizes[EGDS_TEXT_DISTANCE_X] = 3;
		Sizes[EGDS_TEXT_DISTANCE_Y] = 2;
	}

	Texts[EGDT_MSG_BOX_OK] = L"OK";
	Texts[EGDT_MSG_BOX_CANCEL] = L"Cancel";
	Texts[EGDT_MSG_BOX_YES] = L"Yes";
	Texts[EGDT_MSG_BOX_NO] = L"No";
	Texts[EGDT_WINDOW_CLOSE] = L"Close";
	Texts[EGDT_WINDOW_RESTORE] = L"Restore";
	Texts[EGDT_WINDOW_MINIMIZE] = L"Minimize";
	Texts[EGDT_WINDOW_MAXIMIZE] = L"Maximize";

	Icons[EGDI_WINDOW_MAXIMIZE] = 225;
	Icons[EGDI_WINDOW_RESTORE] = 226;
	Icons[EGDI_WINDOW_CLOSE] = 227;
	Icons[EGDI_WINDOW_MINIMIZE] = 228;
	Icons[EGDI_CURSOR_UP] = 229;
	Icons[EGDI_CURSOR_DOWN] = 230;
	Icons[EGDI_CURSOR_LEFT] = 231;
	Icons[EGDI_CURSOR_RIGHT] = 232;
	Icons[EGDI_MENU_MORE] = 232;
	Icons[EGDI_CHECK_BOX_CHECKED] = 233;
	Icons[EGDI_DROP_DOWN] = 234;
	Icons[EGDI_SMALL_CURSOR_UP] = 235;
	Icons[EGDI_SMALL_CURSOR_DOWN] = 236;
	Icons[EGDI_RADIO_BUTTON_CHECKED] = 237;
	Icons[EGDI_FILE] = 238;
	Icons[EGDI_DIRECTORY] = 239;

	for (u32 i=0; i<EGDF_COUNT; ++i)
		Fonts[i] = 0;

	UseGradient = (Type == EGST_WINDOWS_METALLIC) ||
				  (Type == EGST_BURNING_SKIN) ;
}


//! destructor
CGUISkin::~CGUISkin()
{
	for (u32 i=0; i<EGDF_COUNT; ++i)
	{
		if (Fonts[i])
			Fonts[i]->drop();
	}

	if (SpriteBank)
		SpriteBank->drop();
}



//! returns default color
video::SColor CGUISkin::getColor(EGUI_DEFAULT_COLOR color)
{
	return Colors[color];
}


//! sets a default color
void CGUISkin::setColor(EGUI_DEFAULT_COLOR which, video::SColor newColor)
{
	if (which>=0 && which<= EGDC_COUNT)
		Colors[which] = newColor;
}


//! returns default color
s32 CGUISkin::getSize(EGUI_DEFAULT_SIZE size)
{
	return Sizes[size];
}



//! sets a default size
void CGUISkin::setSize(EGUI_DEFAULT_SIZE which, s32 size)
{
	if (which >= 0 && which <= EGDS_COUNT)
		Sizes[which] = size;
}



//! returns the default font
IGUIFont* CGUISkin::getFont(EGUI_DEFAULT_FONT which)
{
	if (Fonts[which])
		return Fonts[which];
	else
		return Fonts[EGDF_DEFAULT];
}

//! sets a default font
void CGUISkin::setFont(IGUIFont* font, EGUI_DEFAULT_FONT which)
{
	if (Fonts[which])
		Fonts[which]->drop();

	Fonts[which] = font;

	if (Fonts[which])
		Fonts[which]->grab();
}

IGUISpriteBank* CGUISkin::getSpriteBank()
{
	return SpriteBank;
}

void CGUISkin::setSpriteBank(IGUISpriteBank* bank)
{
	if (SpriteBank)
		SpriteBank->drop();

	if (bank)
		bank->grab();

	SpriteBank = bank;
}

//! Returns a default icon
u32 CGUISkin::getIcon(EGUI_DEFAULT_ICON icon)
{
	return Icons[icon];
}

//! Sets a default icon
void CGUISkin::setIcon(EGUI_DEFAULT_ICON icon, u32 index)
{
	Icons[icon] = index;
}

//! Returns a default text. For example for Message box button captions:
//! "OK", "Cancel", "Yes", "No" and so on.
const wchar_t* CGUISkin::getDefaultText(EGUI_DEFAULT_TEXT text)
{
	return Texts[text].c_str();
}


//! Sets a default text. For example for Message box button captions:
//! "OK", "Cancel", "Yes", "No" and so on.
void CGUISkin::setDefaultText(EGUI_DEFAULT_TEXT which, const wchar_t* newText)
{
	Texts[which] = newText;
}

//! draws a standard 3d button pane
/**	Used for drawing for example buttons in normal state.
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details.
\param rect: Defining area where to draw.
\param clip: Clip area.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex
implementations to find out how to draw the part exactly. */
void CGUISkin::draw3DButtonPaneStandard(IGUIElement* element,
										const core::rect<s32>& r,
										const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> rect = r;

	if ( Type == EGST_BURNING_SKIN )
	{
		rect.UpperLeftCorner.X -= 1;
		rect.UpperLeftCorner.Y -= 1;
		rect.LowerRightCorner.X += 1;
		rect.LowerRightCorner.Y += 1;
		draw3DSunkenPane(element,
						getColor( EGDC_WINDOW ).getInterpolated( 0xFFFFFFFF, 0.9f )
						,false, true, rect, clip);
		return;
	}

	Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

	rect.LowerRightCorner.X -= 1;
	rect.LowerRightCorner.Y -= 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

	rect.UpperLeftCorner.X += 1;
	rect.UpperLeftCorner.Y += 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

	rect.LowerRightCorner.X -= 1;
	rect.LowerRightCorner.Y -= 1;

	if (!UseGradient)
	{
		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, clip);
	}
	else
	{
		video::SColor c1 = getColor(EGDC_3D_FACE);
		video::SColor c2 = c1.getInterpolated(getColor(EGDC_3D_DARK_SHADOW), 0.4f);
		Driver->draw2DRectangle(rect, c1, c1, c2, c2, clip);
	}
}


//! draws a pressed 3d button pane
/**	Used for drawing for example buttons in pressed state.
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details.
\param rect: Defining area where to draw.
\param clip: Clip area.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex
implementations to find out how to draw the part exactly. */
void CGUISkin::draw3DButtonPanePressed(IGUIElement* element,
	const core::rect<s32>& r,
	const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> rect = r;
	Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

	rect.LowerRightCorner.X -= 1;
	rect.LowerRightCorner.Y -= 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

	rect.UpperLeftCorner.X += 1;
	rect.UpperLeftCorner.Y += 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

	rect.UpperLeftCorner.X += 1;
	rect.UpperLeftCorner.Y += 1;

	if (!UseGradient)
	{
		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, clip);
	}
	else
	{
		video::SColor c1 = getColor(EGDC_3D_FACE);
		video::SColor c2 = c1.getInterpolated(getColor(EGDC_3D_DARK_SHADOW), 0.4f);
		Driver->draw2DRectangle(rect, c1, c1, c2, c2, clip);
	}
}


//! draws a sunken 3d pane
/** Used for drawing the background of edit, combo or check boxes.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex
implementations to find out how to draw the part exactly.
\param bgcolor: Background color.
\param flat: Specifies if the sunken pane should be flat or displayed as sunken
 deep into the ground.
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CGUISkin::draw3DSunkenPane(IGUIElement* element,
	video::SColor bgcolor, bool flat, bool fillBackGround,
	const core::rect<s32>& r,
	const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> rect = r;


	if (flat)
	{
		// draw flat sunken pane
		if (fillBackGround)
			Driver->draw2DRectangle(bgcolor, rect, clip);

		rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

		rect = r;
		rect.UpperLeftCorner.X = rect.LowerRightCorner.X - 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

		rect = r;
		rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1;
		rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);
	}
	else
	{
		// draw deep sunken pane
		if (fillBackGround)
			Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

		rect.LowerRightCorner.X -= 1;
		rect.LowerRightCorner.Y -= 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

		rect.UpperLeftCorner.X += 1;
		rect.UpperLeftCorner.Y += 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_LIGHT), rect, clip);

		rect.LowerRightCorner.X -= 1;
		rect.LowerRightCorner.Y -= 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

		rect.UpperLeftCorner.X += 1;
		rect.UpperLeftCorner.Y += 1;
		Driver->draw2DRectangle(bgcolor, rect, clip);
	}
}


//! draws a window background
/** Used for drawing the background of dialogs and windows.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex
implementations to find out how to draw the part exactly.
\param titleBarColor: Title color.
\param drawTitleBar: True to enable title drawing.
\param rect: Defining area where to draw.
\param clip: Clip area.
\return Returns rect where to draw title bar text. */
core::rect<s32> CGUISkin::draw3DWindowBackground(IGUIElement* element,
	bool drawTitleBar, video::SColor titleBarColor,
	const core::rect<s32>& r,
	const core::rect<s32>* cl)
{
	if (!Driver)
		return r;

	core::rect<s32> rect = r;


	rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, cl);

	rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
	rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, cl);

	rect.UpperLeftCorner.X = r.LowerRightCorner.X - 1;
	rect.LowerRightCorner.X = r.LowerRightCorner.X;
	rect.UpperLeftCorner.Y = r.UpperLeftCorner.Y;
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
	Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, cl);

	rect.UpperLeftCorner.X -= 1;
	rect.LowerRightCorner.X -= 1;
	rect.UpperLeftCorner.Y += 1;
	rect.LowerRightCorner.Y -= 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, cl);

	rect.UpperLeftCorner.X = r.UpperLeftCorner.X;
	rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1;
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
	rect.LowerRightCorner.X = r.LowerRightCorner.X;
	Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, cl);

	rect.UpperLeftCorner.X += 1;
	rect.LowerRightCorner.X -= 1;
	rect.UpperLeftCorner.Y -= 1;
	rect.LowerRightCorner.Y -= 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, cl);

	rect = r;
	rect.UpperLeftCorner.X +=1;
	rect.UpperLeftCorner.Y +=1;
	rect.LowerRightCorner.X -= 2;
	rect.LowerRightCorner.Y -= 2;

	if (!UseGradient)
	{
		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, cl);
	}
	else
	if ( Type == EGST_BURNING_SKIN )
	{
		video::SColor c1 = getColor(EGDC_WINDOW).getInterpolated ( 0xFFFFFFFF, 0.9f );
		video::SColor c2 = getColor(EGDC_WINDOW).getInterpolated ( 0xFFFFFFFF, 0.8f );

		Driver->draw2DRectangle(rect, c1, c1, c2, c2, cl);
	}
	else
	{
		video::SColor c2 = getColor(EGDC_3D_SHADOW);
		video::SColor c1 = getColor(EGDC_3D_FACE);
		Driver->draw2DRectangle(rect, c1, c1, c1, c2, cl);
	}

	rect = r;
	rect.UpperLeftCorner.X += 2;
	rect.UpperLeftCorner.Y += 2;
	rect.LowerRightCorner.X -= 2;
	rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + getSize(EGDS_WINDOW_BUTTON_WIDTH) + 2;

	if (drawTitleBar)
	{
		// draw title bar
		//if (!UseGradient)
		//	Driver->draw2DRectangle(titleBarColor, rect, cl);
		//else
		if ( Type == EGST_BURNING_SKIN )
		{
			video::SColor c = titleBarColor.getInterpolated( 0xffffffff, 0.8f);
			Driver->draw2DRectangle(rect, titleBarColor, titleBarColor, c, c, cl);
		}
		else
		{
			video::SColor c = titleBarColor.getInterpolated(video::SColor(255,0,0,0), 0.2f);
			Driver->draw2DRectangle(rect, titleBarColor, c, titleBarColor, c, cl);
		}
	}

	return rect;
}


//! draws a standard 3d menu pane
/**	Used for drawing for menus and context menus.
It uses the colors EGDC_3D_DARK_SHADOW, EGDC_3D_HIGH_LIGHT, EGDC_3D_SHADOW and
EGDC_3D_FACE for this. See EGUI_DEFAULT_COLOR for details.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex
implementations to find out how to draw the part exactly.
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CGUISkin::draw3DMenuPane(IGUIElement* element,
			const core::rect<s32>& r, const core::rect<s32>* clip)
{
	if ( Type == EGST_BURNING_SKIN )
	{	
		core::rect<s32> rect = r;
		rect.UpperLeftCorner.Y -= 3;
		draw3DButtonPaneStandard(element, rect, clip);
		return;
	}

	if (!Driver)
		return;

	// in this skin, this is exactly what non pressed buttons look like,
	// so we could simply call
	// draw3DButtonPaneStandard(element, rect, clip);
	// here.
	// but if the skin is transparent, this doesn't look that nice. So
	// We draw it a little bit better, with some more draw2DRectangle calls,
	// but there aren't that much menus visible anyway.

	core::rect<s32> rect = r;
	rect.LowerRightCorner.Y = rect.UpperLeftCorner.Y + 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

	rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
	rect.LowerRightCorner.X = rect.UpperLeftCorner.X + 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), rect, clip);

	rect.UpperLeftCorner.X = r.LowerRightCorner.X - 1;
	rect.LowerRightCorner.X = r.LowerRightCorner.X;
	rect.UpperLeftCorner.Y = r.UpperLeftCorner.Y;
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
	Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

	rect.UpperLeftCorner.X -= 1;
	rect.LowerRightCorner.X -= 1;
	rect.UpperLeftCorner.Y += 1;
	rect.LowerRightCorner.Y -= 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

	rect.UpperLeftCorner.X = r.UpperLeftCorner.X;
	rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1;
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
	rect.LowerRightCorner.X = r.LowerRightCorner.X;
	Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), rect, clip);

	rect.UpperLeftCorner.X += 1;
	rect.LowerRightCorner.X -= 1;
	rect.UpperLeftCorner.Y -= 1;
	rect.LowerRightCorner.Y -= 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

	rect = r;
	rect.UpperLeftCorner.X +=1;
	rect.UpperLeftCorner.Y +=1;
	rect.LowerRightCorner.X -= 2;
	rect.LowerRightCorner.Y -= 2;

	if (!UseGradient)
		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, clip);
	else
	{
		video::SColor c1 = getColor(EGDC_3D_FACE);
		video::SColor c2 = getColor(EGDC_3D_SHADOW);
		Driver->draw2DRectangle(rect, c1, c1, c2, c2, clip);
	}
}


//! draws a standard 3d tool bar
/**	Used for drawing for toolbars and menus.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex
implementations to find out how to draw the part exactly.
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CGUISkin::draw3DToolBar(IGUIElement* element,
	const core::rect<s32>& r,
	const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> rect = r;

	rect.UpperLeftCorner.X = r.UpperLeftCorner.X;
	rect.UpperLeftCorner.Y = r.LowerRightCorner.Y - 1;
	rect.LowerRightCorner.Y = r.LowerRightCorner.Y;
	rect.LowerRightCorner.X = r.LowerRightCorner.X;
	Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), rect, clip);

	rect = r;
	rect.LowerRightCorner.Y -= 1;

	if (!UseGradient)
	{
		Driver->draw2DRectangle(getColor(EGDC_3D_FACE), rect, clip);
	}
	else
	if ( Type == EGST_BURNING_SKIN )
	{
		video::SColor c1 = 0xF0000000 | getColor(EGDC_3D_FACE).color;
		video::SColor c2 = 0xF0000000 | getColor(EGDC_3D_SHADOW).color;

		rect.LowerRightCorner.Y += 1;
		Driver->draw2DRectangle(rect, c1, c2, c1, c2, clip);

	}
	else
	{
		video::SColor c1 = getColor(EGDC_3D_FACE);
		video::SColor c2 = getColor(EGDC_3D_SHADOW);
		Driver->draw2DRectangle(rect, c1, c1, c2, c2, clip);
	}
}

//! draws a tab button
/**	Used for drawing for tab buttons on top of tabs.
\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex
implementations to find out how to draw the part exactly.
\param active: Specifies if the tab is currently active.
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CGUISkin::draw3DTabButton(IGUIElement* element, bool active,
	const core::rect<s32>& frameRect, const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> tr = frameRect;

	tr.LowerRightCorner.X -= 2;
	tr.LowerRightCorner.Y = tr.UpperLeftCorner.Y + 1;
	tr.UpperLeftCorner.X += 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), tr, clip);

	// draw left highlight
	tr = frameRect;
	tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1;
	tr.UpperLeftCorner.Y += 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), tr, clip);

	// draw grey background
	tr = frameRect;
	tr.UpperLeftCorner.X += 1;
	tr.UpperLeftCorner.Y += 1;
	tr.LowerRightCorner.X -= 2;
	Driver->draw2DRectangle(getColor(EGDC_3D_FACE), tr, clip);

	// draw right middle gray shadow
	tr.LowerRightCorner.X += 1;
	tr.UpperLeftCorner.X = tr.LowerRightCorner.X - 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), tr, clip);

	tr.LowerRightCorner.X += 1;
	tr.UpperLeftCorner.X += 1;
	tr.UpperLeftCorner.Y += 1;
	Driver->draw2DRectangle(getColor(EGDC_3D_DARK_SHADOW), tr, clip);
}


//! draws a tab control body
/**	\param element: Pointer to the element which whiches to draw this. This parameter
is usually not used by ISkin, but can be used for example by more complex
implementations to find out how to draw the part exactly.
\param border: Specifies if the border should be drawn.
\param background: Specifies if the background should be drawn.
\param rect: Defining area where to draw.
\param clip: Clip area.	*/
void CGUISkin::draw3DTabBody(IGUIElement* element, bool border, bool background,
	const core::rect<s32>& rect, const core::rect<s32>* clip)
{
	if (!Driver)
		return;

	core::rect<s32> tr = rect;

	// draw border.
	if (border)
	{
		// draw left hightlight
		tr.UpperLeftCorner.Y += getSize(gui::EGDS_BUTTON_HEIGHT) + 2;
		tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_HIGH_LIGHT), tr, clip);

		// draw right shadow
		tr.UpperLeftCorner.X = rect.LowerRightCorner.X - 1;
		tr.LowerRightCorner.X = tr.UpperLeftCorner.X + 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), tr, clip);

		// draw lower shadow
		tr = rect;
		tr.UpperLeftCorner.Y = tr.LowerRightCorner.Y - 1;
		Driver->draw2DRectangle(getColor(EGDC_3D_SHADOW), tr, clip);
	}

	if (background)
	{
		tr = rect;
		tr.UpperLeftCorner.Y += getSize(gui::EGDS_BUTTON_HEIGHT) + 2;
		tr.LowerRightCorner.X -= 1;
		tr.UpperLeftCorner.X += 1;
		tr.LowerRightCorner.Y -= 1;

		if (!UseGradient)
			Driver->draw2DRectangle(getColor(EGDC_3D_FACE), tr, clip);
		else
		{
			video::SColor c1 = getColor(EGDC_3D_FACE);
			video::SColor c2 = getColor(EGDC_3D_SHADOW);
			Driver->draw2DRectangle(tr, c1, c1, c2, c2, clip);
		}
	}
}

//! draws an icon, usually from the skin's sprite bank
/**	\param parent: Pointer to the element which wishes to draw this icon. 
This parameter is usually not used by IGUISkin, but can be used for example 
by more complex implementations to find out how to draw the part exactly. 
\param icon: Specifies the icon to be drawn.
\param position: The position to draw the icon
\param starttime: The time at the start of the animation
\param currenttime: The present time, used to calculate the frame number
\param loop: Whether the animation should loop or not
\param clip: Clip area.	*/
void CGUISkin::drawIcon(IGUIElement* element, EGUI_DEFAULT_ICON icon,
			const core::position2di position, u32 starttime, u32 currenttime, 
			bool loop, const core::rect<s32>* clip)
{
	if (!SpriteBank)
		return;

	SpriteBank->draw2DSprite(Icons[icon], position, clip, 
			video::SColor(255,0,0,0), starttime, currenttime, loop, true);

}

EGUI_SKIN_TYPE CGUISkin::getType() const
{
	return Type;
}

//! draws a 2d rectangle.
void CGUISkin::draw2DRectangle(IGUIElement* element, video::SColor &color, const core::rect<s32>& pos, 
					 const core::rect<s32>* clip)
{
	Driver->draw2DRectangle(color, pos, clip);
}

//! Writes attributes of the object.
//! Implement this to expose the attributes of your scene node animator for 
//! scripting languages, editors, debuggers or xml serialization purposes.
void CGUISkin::serializeAttributes(io::IAttributes* out, io::SAttributeReadWriteOptions* options) 
{
	u32 i;
	for (i=0; i<EGDC_COUNT; ++i)
		out->addColor(GUISkinColorNames[i], Colors[i]);

	for (i=0; i<EGDS_COUNT; ++i)
		out->addInt(GUISkinSizeNames[i], Sizes[i]);

	for (i=0; i<EGDT_COUNT; ++i)
		out->addString(GUISkinTextNames[i], Texts[i].c_str());

	for (i=0; i<EGDI_COUNT; ++i)
		out->addInt(GUISkinIconNames[i], Icons[i]);
}

//! Reads attributes of the object.
//! Implement this to set the attributes of your scene node animator for 
//! scripting languages, editors, debuggers or xml deserialization purposes.
void CGUISkin::deserializeAttributes(io::IAttributes* in, io::SAttributeReadWriteOptions* options)
{
	u32 i;
	for (i=0; i<EGDC_COUNT; ++i)
		Colors[i] = in->getAttributeAsColor(GUISkinColorNames[i]);

	for (i=0; i<EGDS_COUNT; ++i)
		Sizes[i] = in->getAttributeAsInt(GUISkinSizeNames[i]);

	for (i=0; i<EGDT_COUNT; ++i)
		Texts[i] = in->getAttributeAsStringW(GUISkinTextNames[i]);

	for (i=0; i<EGDI_COUNT; ++i)
		Icons[i] = in->getAttributeAsInt(GUISkinIconNames[i]);

}


} // end namespace gui
} // end namespace irr

