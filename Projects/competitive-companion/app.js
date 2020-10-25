// Constants
const port = 10043;

// Requires
const app = require('express')();
const bodyParser = require('body-parser');
const fs = require('fs');

const { dir, separator } = require('./statics');

// Functions
function updateFile(path, data) {
    fs.writeFile(path, data, (err) => {
        if (err)
            throw err;
    });
}

app.use(bodyParser.json());

app.post('/', (req, res) => {
    const data = req.body;

    // Adding title into 1.cpp
    var code = `// ${data.name}\n`;
    fs.readFile(dir + '1.cpp', (err, data) => {
        if (err)
            throw err;
        if (data)
            code += data.toString();
        updateFile(dir + '1.cpp', code);
    });

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