// Constants
const port = 10043;

// NPM Packages
const app = require('express')();
const bodyParser = require('body-parser');
const fs = require('fs');

// Functions and Constants, imported from statics.js
const {
    dir,
    separator,
    updateFile,
    readFile,
    removeTitle
} = require('./statics');

app.use(bodyParser.json());

app.post('/', (req, res) => {
    const data = req.body;

    // Adding title into 1.cpp
    var code = `// ${data.name}\n`;
    // removesTitle => readsFile => updatesFile
    removeTitle(() => readFile(dir + '1.cpp', (data) => updateFile(dir + '1.cpp', code + data)));

    // Parsing input and output
    var inputs = '';
    var outputs = '';

    data.tests.forEach((t) => {
        inputs += t.input.trim() + separator;
        outputs += t.output.trim() + separator;
    });

    updateFile(dir + 'ParsedInput.txt', inputs);
    updateFile(dir + 'ParsedOutput.txt', outputs);

    res.sendStatus(200);
});

app.listen(port, err => {
    if (err) {
        console.log(err);
        process.exit(1);
    }
    console.log(`Listening to port ${port}.`);
});