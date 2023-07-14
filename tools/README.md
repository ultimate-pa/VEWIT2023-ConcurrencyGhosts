# Concurrency Correctness Witnesses with Ghosts

## Build witness schema documentation
The schema documentation for the YAML-based witness format with ghosts can be automatically built using the following Makefile target:
```shell
make build
```
The built Web documentation of the witness schema is then located under `output/schema/doc`.

## Validate program and witness files
The structure and syntax of all concurrent programs and witness files in this project can be validated using the following Makefile target:
```shell
make validate
```
This generic Makefile target depends on other Makefile targets doing the linting as well as validating the syntax of all programs and witness files.

## Verify concurrent programs
All concurrent programs in this project can be verified with Ultimate GemCutter using the following Makefile target:
```shell
make verify
```
The analysis output of Ultimate from a verification run of each program is written to log files located under `output/ultimate/log`.

## Required tools and packages
The following tools and packages are required by the Makefile targets to work properly:

  - `gcc`                    (https://gcc.gnu.org)
  - `clang-tidy`             (https://github.com/llvm/llvm-project)
  - `yamllint`               (https://github.com/adrienverge/yamllint)
  - `yajsv`                  (https://github.com/neilpa/yajsv)
  - `json-schema-for-humans` (https://github.com/coveooss/json-schema-for-humans)
  - `Ultimate`               (https://github.com/ultimate-pa/ultimate)
