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

/**
 * Interface for a stream of tokens.
 *
 * @author Paul Gazzillo
 */
public interface Stream {
  /**
   * Get the next token in the stream.
   *
   * @return The next token from the stream.
   */
  public Syntax scan() throws java.io.IOException;

  /**
   * Indicates the stream is over.
   *
   * @return true if the stream is over.
   */
  public boolean done();
}
