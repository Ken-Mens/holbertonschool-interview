#!/usr/bin/node

const request = require('request');

async function starwar (id) {
  const url = `https://swapi-api.hbtn.io/api/films/${id}`;

  request(url, async function (err, res, body) {
    if (err) {
      console.log(err);
    } else {
       let new_hope = JSON.parse(body).characters;
      for (const char of new_hope) {
        const ok = () => {
          return new Promise((resolve, reject) => {
            request(char, function (err, res, body) {
              if (err && res.statusCode === 200) {
                console.log(err);
              } else {
                resolve(JSON.parse(body).name);
              }
            });
          });
        };
        console.log(await ok());
      }
    }
  });
}

if (process.argv.length === 3) {
  starwar(process.argv[2]);
}

 if (process.argv.length < 3) {
  console.error('Missing argument');
  process.exit(1);
}