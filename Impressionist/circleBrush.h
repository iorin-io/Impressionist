#pragma once
//
// circleBrushh
//
// The header file for Point Brush. 
//

#ifndef CIRCLEBRUSH_H
#define CIRCLEBRUSH_H

#include "impBrush.h"

class CircleBrush : public ImpBrush
{
public:
	CircleBrush( ImpressionistDoc* pDoc = NULL, char* name = NULL );

	void BrushBegin( const Point source, const Point target );
	void BrushMove( const Point source, const Point target );
	void BrushEnd( const Point source, const Point target );
	char* BrushName( void );
};

#endif
