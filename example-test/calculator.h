/* Copyright (C) <2014>  Gokul Kartha <kartha.gokul@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
**/

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <cmath>

template<typename Type>
class Calculator
{
public:
    Type cubic(Type d)
    {
        return pow(d,3);
    }

    Type multiply(Type a,Type b)
    {
        return a*b;
    }

    Type sum(Type a,Type b)
    {
        return a+b;
    }

    Type divide(Type a,Type b)
    {
        return a/b;
    }
};

#endif // CALCULATOR_H
