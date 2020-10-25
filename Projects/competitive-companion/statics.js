// NPM Packages
const { debug } = require('console');
const fs = require('fs');

// Constants
const dir = 'D:/Dhruv/Codes/C++/';
const separator = '\n$###%###%#############%###%###$\n';

// Functions
function updateFile(path, data, fxn = () => {}) {
    fs.writeFile(path, data, (err) => {
        if (err)
            throw err;
        fxn();
    });
}

function readFile(path, fxn) {
    fs.readFile(path, { encoding: 'utf8' }, (err, data) => {
        if (err)
            throw err;
        let code = '';
        if (data)
            code += data;
        fxn(code);
    });
}

function removeTitle(fxn = () => {}) {
    readFile(dir + '1.cpp', (code) => {
        if (code.startsWith('// ')) {
            let new_code = '';
            let fir = true;

            for (let i = 0; i < code.length; i++) {
                var char = code[i];
                if (fir && char == '\n') {
                    fir = false;
                    continue;
                }
                if (!fir)
                    new_code += char;
            }
            updateFile(dir + '1.cpp', new_code, fxn);
        } else {
            fxn();
        }
    });
}

// Exports
module.exports = {
    dir,
    separator,
    updateFile,
    readFile,
    removeTitle
};