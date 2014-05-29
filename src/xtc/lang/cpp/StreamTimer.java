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
 * A stream that times another stream.
 *
 * @author Paul Gazzillo
 */
public class StreamTimer implements Stream {
  /** The stream to time. */
  Stream stream;

  /** The stopwatch to use for timing. */
  StopWatch stopWatch;

  /**
   * Create a new stream timer.
   *
   * @param stream The stream to time.
   * @param stopWatch the stopwatch to use for timing.
   */
  public StreamTimer(Stream stream, StopWatch stopWatch) {
    this.stream = stream;
    this.stopWatch = stopWatch;
  }

  public Syntax scan() throws java.io.IOException {
    Syntax syntax;

    stopWatch.start();
    syntax = stream.scan();
    stopWatch.stop();

    return syntax;
  }

  public boolean done() {
    return stream.done();
  }
}
