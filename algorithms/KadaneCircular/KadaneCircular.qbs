import qbs

CppApplication {
    consoleApplication: true
    files: "KadaneCircular.cpp"

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
