package com.automatak.render.dnp3.objects.groups

import com.automatak.render.dnp3.objects.{FixedSize, FixedSizeField, ObjectGroup}
import FixedSizeField._

// frozen counter events
object Group23 extends ObjectGroup {
  def objects = List(Group23Var1, Group23Var2, Group23Var5, Group23Var6)
  def group: Byte = 23
}

object Group23Var1 extends FixedSize(Group23, 1)(flags, count32)
object Group23Var2 extends FixedSize(Group23, 2)(flags, count16)
object Group23Var5 extends FixedSize(Group23, 5)(flags, count32, time48)
object Group23Var6 extends FixedSize(Group23, 6)(flags, count16, time48)