#pragma once
//
// triangleBrush.h
//
// The header file for Point Brush.
//

#ifndef SIZECHANGEBRUSH_H
#define SIZECHANGEBRUSH_H

#include "impBrush.h"

class SizeChangeBrush : public ImpBrush
{
public:
	SizeChangeBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif
