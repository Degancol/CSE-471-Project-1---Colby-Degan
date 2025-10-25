# CSE 471 Project 1: Additive Synthesis - Colby Degan
This is my submission for Project 1 for Michigan State University's CSE 471, in which I implement additive synthesis.

## score File Format:
Example:
no
```
<?xml version="1.0" encoding="utf-8"?>
<score bpm="120" beatspermeasure="4">
   <instrument instrument="AdditiveSynth">
      <note measure="1" beat="1" duration="1" amplitudes="1 .7 .5" note="C5" ADSR=".1 .1 .8 .3" vibrato="2.0 0.6"/>
      <!-- Notes are continued in the same format as the previous note -->
    </instrument>
</score>
```

Where:
"bpm" is the number of beats per minute
"beatspermeasure" is the bumber of beats that occur each measure
"measure" is the measure the note is played in
"beat" is the beat the note is played in the note's measure
"duration" is how long the note is played for
"amplitudes" are the relative amplitudes of the harmonic components used in additive synthesis
      The first value is the fundamental frequency
      The second value is the 2nd harmonic
      The third value is the 3rd harmonic
"note" is the pitch of the note
"ADSR" describes how the volume of the note changes over time
      The first value is the attack (time to reach full volume)
      The second value is the decay (time to fall from peak to sustain level)
      The third value is the sustain (sustain level as a fraction of the maximum amplitude)
      The fourth value is the release (time to fade out after the key is released)
"vibrato" defines the vibrato effect (periodic pitch modulation)
      The first value is the rate of the vibrato
      The second value is the frequency of the vibrato
  

