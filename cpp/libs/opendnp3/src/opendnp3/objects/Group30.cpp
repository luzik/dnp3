//
//  _   _         ______    _ _ _   _             _ _ _
// | \ | |       |  ____|  | (_) | (_)           | | | |
// |  \| | ___   | |__   __| |_| |_ _ _ __   __ _| | | |
// | . ` |/ _ \  |  __| / _` | | __| | '_ \ / _` | | | |
// | |\  | (_) | | |___| (_| | | |_| | | | | (_| |_|_|_|
// |_| \_|\___/  |______\__,_|_|\__|_|_| |_|\__, (_|_|_)
//                                           __/ |
//                                          |___/
// 
// This file is auto-generated. Do not edit manually
// 
// Copyright 2013 Automatak LLC
// 
// Automatak LLC (www.automatak.com) licenses this file
// to you under the the Apache License Version 2.0 (the "License"):
// 
// http://www.apache.org/licenses/LICENSE-2.0.html
//

#include "Group30.h"

#include "opendnp3/app/MeasurementFactory.h"
#include "opendnp3/app/WriteConversions.h"
#include <openpal/serialization/Format.h>
#include <openpal/serialization/Parse.h>

using namespace openpal;

namespace opendnp3 {

bool Group30Var1::Read(ReadBufferView& buffer, Group30Var1& output)
{
  return Parse::Many(buffer, output.flags, output.value);
}

bool Group30Var1::Write(const Group30Var1& arg, openpal::WriteBufferView& buffer)
{
  return Format::Many(buffer, arg.flags, arg.value);
}


bool Group30Var1::ReadTarget(ReadBufferView& buff, Analog& output)
{
  Group30Var1 value;
  if(Read(buff, value))
  {
    output = AnalogFactory::From(value.flags, value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group30Var1::WriteTarget(const Analog& value, openpal::WriteBufferView& buff)
{
  return Group30Var1::Write(ConvertGroup30Var1::Apply(value), buff);
}


bool Group30Var2::Read(ReadBufferView& buffer, Group30Var2& output)
{
  return Parse::Many(buffer, output.flags, output.value);
}

bool Group30Var2::Write(const Group30Var2& arg, openpal::WriteBufferView& buffer)
{
  return Format::Many(buffer, arg.flags, arg.value);
}


bool Group30Var2::ReadTarget(ReadBufferView& buff, Analog& output)
{
  Group30Var2 value;
  if(Read(buff, value))
  {
    output = AnalogFactory::From(value.flags, value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group30Var2::WriteTarget(const Analog& value, openpal::WriteBufferView& buff)
{
  return Group30Var2::Write(ConvertGroup30Var2::Apply(value), buff);
}


bool Group30Var3::Read(ReadBufferView& buffer, Group30Var3& output)
{
  return Parse::Many(buffer, output.value);
}

bool Group30Var3::Write(const Group30Var3& arg, openpal::WriteBufferView& buffer)
{
  return Format::Many(buffer, arg.value);
}


bool Group30Var3::ReadTarget(ReadBufferView& buff, Analog& output)
{
  Group30Var3 value;
  if(Read(buff, value))
  {
    output = AnalogFactory::From(value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group30Var3::WriteTarget(const Analog& value, openpal::WriteBufferView& buff)
{
  return Group30Var3::Write(ConvertGroup30Var3::Apply(value), buff);
}


bool Group30Var4::Read(ReadBufferView& buffer, Group30Var4& output)
{
  return Parse::Many(buffer, output.value);
}

bool Group30Var4::Write(const Group30Var4& arg, openpal::WriteBufferView& buffer)
{
  return Format::Many(buffer, arg.value);
}


bool Group30Var4::ReadTarget(ReadBufferView& buff, Analog& output)
{
  Group30Var4 value;
  if(Read(buff, value))
  {
    output = AnalogFactory::From(value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group30Var4::WriteTarget(const Analog& value, openpal::WriteBufferView& buff)
{
  return Group30Var4::Write(ConvertGroup30Var4::Apply(value), buff);
}


bool Group30Var5::Read(ReadBufferView& buffer, Group30Var5& output)
{
  return Parse::Many(buffer, output.flags, output.value);
}

bool Group30Var5::Write(const Group30Var5& arg, openpal::WriteBufferView& buffer)
{
  return Format::Many(buffer, arg.flags, arg.value);
}


bool Group30Var5::ReadTarget(ReadBufferView& buff, Analog& output)
{
  Group30Var5 value;
  if(Read(buff, value))
  {
    output = AnalogFactory::From(value.flags, value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group30Var5::WriteTarget(const Analog& value, openpal::WriteBufferView& buff)
{
  return Group30Var5::Write(ConvertGroup30Var5::Apply(value), buff);
}


bool Group30Var6::Read(ReadBufferView& buffer, Group30Var6& output)
{
  return Parse::Many(buffer, output.flags, output.value);
}

bool Group30Var6::Write(const Group30Var6& arg, openpal::WriteBufferView& buffer)
{
  return Format::Many(buffer, arg.flags, arg.value);
}


bool Group30Var6::ReadTarget(ReadBufferView& buff, Analog& output)
{
  Group30Var6 value;
  if(Read(buff, value))
  {
    output = AnalogFactory::From(value.flags, value.value);
    return true;
  }
  else
  {
    return false;
  }
}

bool Group30Var6::WriteTarget(const Analog& value, openpal::WriteBufferView& buff)
{
  return Group30Var6::Write(ConvertGroup30Var6::Apply(value), buff);
}



}
