# Concurrency Correctness Witnesses with Ghosts

Here you can find some further material about the talk "Concurrency Correctness Witnesses with Ghosts" at the 1st Workshop on Verification Witnesses and Their Validation (VeWit 2023). In this talk we pursue to improve the format for concurrency correctness witnesses with the introduction of ghost variables.

This repository contains the following materials:

* The [abstract](Abstract.pdf) submitted to the workshop

* The [slides](Slides.pdf) of the talk

* The [examples](examples) shown in the talk as proper C-programs. The folder contains the original program, the YAML-witness and the program that corresponds to this witness (by instrumenting the program with data from the witness, such as ghost variables).

* The [YAML schema](witness.schema.json) of the witness proposal

* The [documentation](docs) generated from the schema. The rendered HTML can be seen [here](https://ultimate-pa.github.io/VEWIT2023-ConcurrencyGhosts).

* The [tools](tools) to check the examples and generate the documentation on your own. Further documentation can be found [here](tools/README.md).