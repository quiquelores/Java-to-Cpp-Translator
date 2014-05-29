/*
 * xtc - The eXTensible Compiler
 * Copyright (C) 2009-2012 New York University
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,
 * USA.
 */
package xtc.lang.cpp;

import xtc.lang.cpp.Syntax.Kind;

/**
 * A stream that filters out all tokens except for regular and
 * compound tokens.
 *
 * @author Paul Gazzillo
 */
public class TokenFilter implements Stream {
  /** The stream to read syntax from. */
  Stream stream;

  /**
   * Create a new token filter stream.
   *
   * @param stream The stream to filter.
   */
  public TokenFilter(Stream stream) {
    this.stream = stream;
  }

  public Syntax scan() throws java.io.IOException {
    Syntax syntax = this.stream.scan();
      
    while (syntax.kind() != Kind.LANGUAGE
           && syntax.kind() != Kind.EOF
           && syntax.kind() != Kind.CONDITIONAL) {
      syntax = this.stream.scan();
    }

    return syntax;
  }

  public boolean done() {
    return this.stream.done();
  }
}
