/*=========================================================================

  Program:   ParaView
  Module:    vtkPVXYChartViewInteractive.cxx

  Copyright (c) Kitware, Inc.
  All rights reserved.
  See Copyright.txt or http://www.paraview.org/HTML/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "vtkPVXYChartViewInteractive.h"

#include "vtkObjectFactory.h"

vtkStandardNewMacro(vtkPVXYChartViewInteractive);

vtkPVXYChartViewInteractive::vtkPVXYChartViewInteractive()
  : vtkPVXYChartView()
{
}

vtkPVXYChartViewInteractive::~vtkPVXYChartViewInteractive() {}

void vtkPVXYChartViewInteractive::PrintSelf(std::ostream& os, vtkIndent indent)
{
  this->Superclass::PrintSelf(os, indent);
}
