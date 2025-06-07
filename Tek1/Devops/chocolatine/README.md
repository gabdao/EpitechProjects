# CHOCOLATINE

## Description
GitHub Actions workflow automation project implementing continuous integration and testing practices. The system enforces coding standards, compilation verification, test execution, and repository mirroring for Epitech projects.

## Objective
Implement a `CHOCOLATINE` project that must:
- Create automated CI/CD pipeline using GitHub Actions
- Enforce coding style standards and compilation checks
- Execute automated testing and repository mirroring
- Integrate workflow triggers based on repository events

### Workflow Architecture
The automation pipeline consists of 4 sequential jobs:
1. **Coding Style Check**: Validates code against Epitech coding standards
2. **Compilation Check**: Verifies program builds and executables exist
3. **Test Execution**: Runs automated test suite
4. **Mirror Push**: Synchronizes with Epitech repository mirror

### Job Requirements
**check_coding_style**:
- Runs in `ghcr.io/epitech/coding-style-checker:latest` container
- Executes `check.sh $(pwd) $(pwd)` command
- Displays coding errors as GitHub annotations with file/line links
- Fails workflow on any coding style violations

**check_program_compilation**:
- Runs in `epitechcontent/epitest-docker` container
- Executes `make` with 2-minute timeout
- Runs `make clean` after compilation
- Verifies all executables from EXECUTABLES variable exist and are executable

**run_tests**:
- Runs in `epitechcontent/epitest-docker` container
- Executes `make tests_run` with 2-minute timeout
- Validates test suite execution

**push_to_mirror**:
- Uses `pixta-dev/repository-mirroring-action`
- Mirrors to repository specified in MIRROR_URL
- Requires GIT_SSH_PRIVATE_KEY secret for authentication
- Only executes on push events (not pull requests)

### Workflow Configuration
**Triggers**:
- Every push to repository
- Every pull request creation
- Excludes branches starting with `ga-ignore-`
- Skips execution when already in mirror repository
