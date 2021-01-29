'use strict';

const buildType = process.config.target_defaults.default_configuration;
const assert = require('assert');

test(require(`../build/${buildType}/binding.node`));
test(require(`../build/${buildType}/binding_noexcept.node`));

function test(binding) {

  const {
    CheckClearTimeout,
    CheckSetTimeout,
    CheckClearInterval,
    CheckSetInterval,
    CheckConsole,
    CheckTextEncoder,
    CheckTextDecoder,
  } = binding.global;

assert.strictEqual(CheckClearTimeout(), true);
assert.strictEqual(CheckSetTimeout(), true);
assert.strictEqual(CheckClearInterval(), true);
assert.strictEqual(CheckSetInterval(), true);
assert.strictEqual(CheckConsole(), true);
assert.strictEqual(CheckTextEncoder(), true);
assert.strictEqual(CheckTextDecoder(), true);

}
