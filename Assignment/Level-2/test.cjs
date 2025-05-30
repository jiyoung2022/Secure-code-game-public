const request = require('supertest');
const server = require('./code.js');

describe('Level-2 Testing', function () {
  it('Level-2 Testing succeed', function (done) {
    request(server)
      .get('/level-2')
      .query({ number: '1e5' })
      .expect('Success!!', done);
  });

  it('Level-2 Testing failed', function (done) {
    request(server)
      .get('/level-2')
      .query({ number: '999' })
      .expect('Failed!!', done);
  });

  after(function () {
    server.close();
  });
});
