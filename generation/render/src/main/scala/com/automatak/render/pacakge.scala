/**
 * Copyright 2013 Automatak, LLC
 *
 * Licensed to Automatak, LLC (www.automatak.com) under one or more
 * contributor license agreements. See the NOTICE file distributed with this
 * work for additional information regarding copyright ownership. Automatak, LLC
 * licenses this file to you under the Apache License Version 2.0 (the "License");
 * you may not use this file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */
package com.automatak

import java.nio.file.{Files, StandardOpenOption, Path}
import java.nio.charset.Charset

package object render {

    def space: Iterator[String] = Iterator.apply("")

    def bracketWithCap[A](indent: Indentation, cap: String)(inner: => Iterator[String]): Iterator[String] = {
      Iterator("{") ++
        indent(
          inner
        ) ++
        Iterator("}"+cap)
    }

    def bracket[A](inner: => Iterator[String])(implicit indent: Indentation): Iterator[String] = bracketWithCap(indent,"")(inner)


    def bracketSemiColon[A](inner: => Iterator[String])(implicit indent: Indentation): Iterator[String] = bracketWithCap(indent,";")(inner)

    implicit class RichStringList(list: List[String]) {

      def spaced : String = list.mkString(" ")

    }

    def delimited(delim: String)(s: Iterator[String]) : Iterator[String] = new Iterator[String] {
      def hasNext: Boolean = s.hasNext

      def next(): String = {
        val ret = s.next()
        if(s.hasNext) (ret + delim) else ret
      }
    }

    def commaDelimited(s: Iterator[String]) : Iterator[String] = delimited(",")(s)

    def writeLinesTo(path: Path, lines: Iterator[String]): Unit = {

      if(!Files.exists(path.getParent)) Files.createDirectory(path.getParent)
      if(!Files.exists(path)) Files.createFile(path)

      val writer = Files.newBufferedWriter( path, Charset.defaultCharset, StandardOpenOption.TRUNCATE_EXISTING)

      def writeLine(s: String) = {
        writer.write(s)
        writer.write(System.lineSeparator)
      }

      try { lines.foreach(writeLine) }
      finally { writer.close() }

    }




}
